CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_hexdump
SRCS = srcs/c_print_memory.c srcs/fi_print_memory.c srcs/file_read.c srcs/ft_atoi.c srcs/ft_putstr.c srcs/c_stdin.c srcs/fi_stdin.c	srcs/ft_error.c	srcs/main.c
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
