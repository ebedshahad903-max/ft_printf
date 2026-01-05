#include "ft_printf.h"

static int  put_unsigned(unsigned int n)
{
    int count = 0;

    if (n >= 10)
        count += put_unsigned(n / 10);
    count += print_char((n % 10) + '0');
    return (count);
}

int print_unsigned(unsigned int n)
{
    return (put_unsigned(n));
}
