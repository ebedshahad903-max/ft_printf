#include "ft_printf.h"

static int  put_hex(unsigned int n, char format)
{
    int     count = 0;
    char    *hex;

    hex = (format == 'x') ? "0123456789abcdef" : "0123456789ABCDEF";

    if (n >= 16)
        count += put_hex(n / 16, format);
    count += print_char(hex[n % 16]);
    return (count);
}

int print_hex(unsigned int n, char format)
{
    return (put_hex(n, format));
}
