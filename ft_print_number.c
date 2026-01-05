#include "ft_printf.h"

static int  putnbr(long n)
{
    int count = 0;

    if (n < 0)
    {
        count += write(1, "-", 1);
        n = -n;
    }
    if (n >= 10)
        count += putnbr(n / 10);
    count += print_char((n % 10) + '0');
    return (count);
}

int print_number(int n)
{
    return (putnbr((long)n));
}
