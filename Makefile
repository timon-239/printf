# **************************************************************************** #
#                                                                              #
#                                                        :::      ::::::::     #
#    Makefile                                          :+:      :+:    :+:     #
#                                                    +:+ +:+         +:+       #
#    By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+          #
#                                                +#+#+#+#+#+   +#+             #
#    Created: 2026/04/30 18:18:25 by tireis           #+#    #+#               #
#    Updated: 2026/05/13 13:13:52 by tireis          ###   ########.fr         #
#                                                                              #
# **************************************************************************** #

NAME        = ft_printf.a
HEADER          = ft_printf.h
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -MMD -MP

SRCS         = ft_printf.c \
              ft_putchar_pf.c \
              ft_puthex_lower.c \
              ft_puthex_upper.c \
              ft_putnb_pf.c \
              ft_putptr_pf.c \
              ft_putstr_pf.c \
              ft_putu_pf.c \

OBJS        = $(SRCS:.c=.o)
DEPS        = $(SRCS:.c=.d)

AR          = ar rcs
RM          = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS) 

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
-include $(DEPS)
