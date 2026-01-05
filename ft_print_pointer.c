#include "ft_printf.h"

static int  put_ptr(unsigned long long n)
{
    int     count = 0;
    char    *hex = "0123456789abcdef";

    if (n >= 16)
        count += put_ptr(n / 16);
    count += print_char(hex[n % 16]);
    return (count);
}

int print_pointer(unsigned long long ptr)
{
    int count = 0;

  count +=write (1,"0x",2);
    if (ptr == 0)
        return (count + write(1, "0", 1));
    count += put_ptr(ptr);
    return (count);
}