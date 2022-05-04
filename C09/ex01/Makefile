CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = $(SRCS:.c=.o) 
INC = -I includes
LIBC = ar rc

all : $(NAME)
%.o : %.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<
$(NAME) : $(OBJS)
	$(LIBC) $(NAME) $(OBJS)
clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all
