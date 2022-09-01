
#ifdef TEST

#include "ft_printf.h"

#include <stdio.h>
#include <limits.h>
#ifdef FT_PRINTF
#define F(...) \
res = ft_printf(__VA_ARGS__);
#else
#define F(...) \
res = printf(__VA_ARGS__);
#endif

int main()
{
	int	res;
	int	i = 100;
	F("[%d]\n", i);
	int	*pointer = &i;
	F("[%p]\n", i);
	F("[%p]", pointer);
//
//	F("[%.0d]\n", -2147483648);
//        F("[%.5d]\n", -2147483648);
//        F("[%.10d]\n", -2147483648);
//        F("[%.20d]\n", -2147483648);
//	return (0);
}
#endif
