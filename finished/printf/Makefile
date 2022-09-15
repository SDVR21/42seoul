# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 20:25:27 by dakim2            #+#    #+#              #
#    Updated: 2022/09/15 22:43:50 by dakim2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS =	ft_printf.c util.c util2.c format.c print.c print2.c
OBJS = $(SRCS:.c=.o)
$(NAME): $(OBJS)
	ar -rcs $@ $^
%.o : %.c
	$(CC) $(CFLAGS) -c $<

all: $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re bonus
