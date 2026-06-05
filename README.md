*This project has been created as part of the 42 curriculum by tireis.*

# ft_printf

## Description
The goal of this project is to recode the famous C library function `printf`. The project focuses on learning about variadic functions in C and creating a versatile, reusable library (`libftprintf.a`). The function handles various format specifiers including characters, strings, pointers, integers, and hexadecimal values.

## Instructions
The project is managed using a `Makefile`.

1.  **Compilation:**
    Run the following command in the root directory:
    ```bash
    make
    ```
    This will generate the `libftprintf.a` library file.

2.  **Usage:**
    Include the header in your C source files:
    ```c
    #include "printf.h"
    ```
    Compile your project by linking the library:
    ```bash
    cc main.c libftprintf.a
    ```

3.  **Maintenance:**
    * `make clean`: Removes object files.
    * `make fclean`: Removes object files and the library.
    * `make re`: Performs a full recompilation.

# Data Structures
*   **va_list:** The `stdarg.h` library is used to handle variable arguments. To ensure the argument list pointer remains consistent across multiple nested function calls (dispatcher vs. sub-functions), a **pointer to the `va_list`** is passed through the functions.

## Resources
[University of Portsmouth - Variadic Functions](https://www.tutorialspoint.com/cprogramming/c_variable_arguments.htm) - A guide on how `va_start`, `va_arg`, and `va_end` work.
[Secrets of printf](https://www.cypress.com/file/54441/download) - An in-depth look at the internal mechanics of formatting functions.
[42 Docs - ft_printf](https://harm-smits.github.io/42docs/projects/ft_printf) - Community documentation regarding the project's requirements.
`man 3 printf` - Official documentation for the standard C library function.

### Use of AI
AI (Gemini/ChatGPT) was used in this project for the following tasks:
*   **Architectural Guidance:** Advice on passing `va_list` by reference to comply with the 25-line function limit and ensure argument synchronization.
*   **Optimization:** Assistance in choosing recursive approaches for base-conversion functions (Hex/Decimal).
*   **Documentation:** Drafting and translating the initial structure and content of this README file.

## Detailed Description: Architecture & Design Choices

When designing this implementation of `ft_printf`, the primary goals were **strict standard compliance (42 Norm)**, **maximum memory safety**, and **bulletproof error handling**. 

Instead of writing a single, massive function with endless nested loops, I chose a highly modular and cascaded architecture. Here is why:

### 1. The Twin-Handler Architecture (`handle_formats` & `handle_formats2`)
The 42 Norm strictly limits functions to a maximum of 25 lines. A full `ft_printf` requires handling at least 9 different format specifiers (`c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, `%`). 

* **Why this way?** I divided the parsing logic into two layered functions: `handle_formats` handles the basic types, and seamlessly passes unknown specifiers down to `handle_formats2`. 
* **The Benefit:** This keeps the codebase incredibly clean, highly readable, and 100% Norm-compliant. More importantly, it makes the project **extremely extensible**. Adding a custom live-coding flag (like `%a` or `%H`) literally takes only a single line of code without risking a Norm violation.

### 2. Cascaded Error Protection (The `-1` Chain)
A common flaw in many `ft_printf` implementations is ignoring the return value of the underlying `write` system call. If a write fails (e.g., closed stdout, broken pipe, or disconnected terminal), a naive printf will keep spinning, incrementing its counter, and return a fake positive length.

* **Why this way?** Every single utility function in this repository (`ft_putchar_pf`, `ft_putstr_pf`, etc.) is fully protected. If `write` returns `-1`, the error is immediately caught and passed back up through the return chain.
* **The Benefit:** If an error occurs halfway through a complex string like `ft_printf("Hello %s World", "42")`, the execution stops instantly, resources are freed via `va_end`, and `ft_printf` correctly aborts and returns `-1`.

### 3. Optimization over Naive Iteration (`ft_putstr_pf`)
Instead of printing strings character-by-character inside a `while` loop (which triggers a costly system call for every single byte), my implementation calculates the string length first and executes **one single `write` call** for the entire string. This significantly reduces system overhead and boosts performance.

### 4. Undefined Behaviour
For undefined behaviour, such as ft_printf("abc%"), my implementation behaves like the original printf on linux systems and returns -1. For unsupported format specifiers otherthan c, s, p, d, i, u, x, X, and %, the behaviour is undefined. In these cases, I also chose to have my implementation behave like the original printf on linux systems, for example with ("hello %y hello") it prints 1:1.  

-----
