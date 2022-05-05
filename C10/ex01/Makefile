CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_cat
SRCS = srcs/file_read.c	srcs/main.c srcs/ft_putstr.c
OBJS = $(SRCS:.c=.o)
INC = -I srcs/ft.h

all : $(NAME)
$(NAME) :
	$(CC) $(CFLAGS) $(INC) -o $(NAME) $(SRCS)
clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all
