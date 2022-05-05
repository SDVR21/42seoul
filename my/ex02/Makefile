CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_tail
SRCS = srcs/file_read.c	srcs/main.c srcs/ft_atoi.c srcs/ft_putstr.c srcs/ft_error.c
OBJS = $(SRCS:.c=.o)
INC = -I srcs/ex02.h

all : $(NAME)
$(NAME) :
	$(CC) $(CFLAGS) $(INC) -o $(NAME) $(SRCS)
clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all
