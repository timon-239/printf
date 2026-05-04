# **************************************************************************** #
#                                                                              #
#                                                        :::      ::::::::     #
#    Makefile                                          :+:      :+:    :+:     #
#                                                    +:+ +:+         +:+       #
#    By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+          #
#                                                +#+#+#+#+#+   +#+             #
#    Created: 2026/04/30 18:18:25 by tireis           #+#    #+#               #
#    Updated: 2026/05/04 14:19:08 by tireis          ###   ########.fr         #
#                                                                              #
# **************************************************************************** #

NAME        = libftprintf.a

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I.

SRC         = ft_printf.c \
              ft_putchar_pf.c \
              ft_puthex_lower.c \
              ft_puthex_upper.c \
              ft_putnb_pf.c \
              ft_putptr_pf.c \
              ft_putstr_pf.c \
              ft_putu_pf.c \
              ft_strlen_pf.c

OBJ         = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
