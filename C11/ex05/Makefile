CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = do-op
SRCS = srcs/ft_operator.c srcs/ft_putnbr.c srcs/main.c
OBJS = $(SRCS:.c=.o)
INC = -I srcs/do_op.h

all :
	$(CC) $(CFLAGS) $(INC) -o $(NAME) $(SRCS)
clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all
