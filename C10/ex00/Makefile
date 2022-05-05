CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_display_file
SRCS = srcs/file_read.c	srcs/main.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)
$(NAME) : 
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)
clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all
