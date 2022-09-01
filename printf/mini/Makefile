all: ft_printf

test:
	./test.sh

printf:
	gcc -Wno-format ft_printf.c -D TEST -o printf

ft_printf:
	gcc ft_printf.c -D TEST -D FT_PRINTF -o ft_printf

clean:
	rm printf ft_printf
