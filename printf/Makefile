NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS =	ft_printf.c util.c format.c print.c util2.c
OBJS = $(SRCS:.c=.o)
AR = ar
ARFLAGS = -rcs
RM = rm
RMFLAGS = -f
all: $(NAME)
clean:
	$(RM) $(RMFLAGS) -f $(OBJS)
fclean: clean
	$(RM) $(RMFLAGS) $(NAME)
re: fclean all
$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^
%.o : %.c
	$(CC) $(CFLAGS) -c $<

printf:
	gcc -Wno-format main.c -D TEST -o printf

ft_printf:
	gcc *.c -D TEST -D FT_PRINTF -o ft_printf
cf:
	rm printf ft_printf
.PHONY: all clean fclean re bonus
