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
    #include "libftprintf.h"
    ```
    Compile your project by linking the library:
    ```bash
    cc main.c libftprintf.a
    ```

3.  **Maintenance:**
    * `make clean`: Removes object files.
    * `make fclean`: Removes object files and the library.
    * `make re`: Performs a full recompilation.

### Data Structures
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

