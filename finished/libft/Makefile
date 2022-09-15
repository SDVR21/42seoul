# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 19:27:44 by dakim2            #+#    #+#              #
#    Updated: 2022/09/01 19:28:12 by dakim2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS =	ft_isalpha.c	\
		ft_isdigit.c	\
		ft_isalnum.c	\
		ft_isascii.c	\
		ft_isprint.c	\
		ft_strlen.c	\
		ft_toupper.c	\
		ft_tolower.c	\
		ft_strchr.c	\
		ft_strrchr.c	\
		ft_memset.c	\
		ft_bzero.c	\
		ft_calloc.c	\
		ft_memcmp.c	\
		ft_strncmp.c	\
		ft_memcpy.c	\
		ft_memchr.c	\
		ft_memmove.c	\
		ft_strlcpy.c	\
		ft_strlcat.c	\
		ft_strnstr.c	\
		ft_strdup.c	\
		ft_atoi.c	\
		ft_substr.c	\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_split.c	\
		ft_itoa.c	\
		ft_strmapi.c	\
		ft_striteri.c	\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putnbr_fd.c	\
		ft_putendl_fd.c	\

SRCS_B =	ft_lstnew.c			\
			ft_lstadd_front.c	\
			ft_lstsize.c		\
			ft_lstlast.c		\
			ft_lstadd_back.c	\
			ft_lstdelone.c		\
			ft_lstclear.c		\
			ft_lstiter.c		\
			ft_lstmap.c

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)
AR = ar
ARFLAGS = -rcs
RM = rm
RMFLAGS = -f
ifdef WITH_BONUS
	TOTAL_OBJS = $(OBJS) $(OBJS_B)
else
	TOTAL_OBJS = $(OBJS)
endif
all: $(NAME)
clean:
	$(RM) $(RMFLAGS) -f $(OBJS) $(OBJS_B)
fclean: clean
	$(RM) $(RMFLAGS) $(NAME)
re: fclean all
bonus :
	make WITH_BONUS=1
$(NAME): $(TOTAL_OBJS)
	$(AR) $(ARFLAGS) $@ $^
%.o : %.c
	$(CC) $(CFLAGS) -c $<

.PHONY: all clean fclean re bonus
