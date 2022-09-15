# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/03 17:56:48 by dakim2            #+#    #+#              #
#    Updated: 2022/09/03 18:32:00 by dakim2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS =	get_next_line.c get_next_line_utils.c main.c


all: gnl

gnl:
	cc -Wall -Wextra -Werror $(SRCS) -D BUFFER_SIZE=$(BS) -o $(NAME)
clean:
	rm -f $(NAME) gnl.txt
#.PHONY: all clean fclean re bonus
