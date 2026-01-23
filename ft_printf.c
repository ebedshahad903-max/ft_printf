#include "ft_printf.h"

static int  specifier_dispatch(char specifier, va_list args)
{
    if (specifier == 'c')
        return (print_char(va_arg(args, int)));
    else if (specifier == 's')
        return (print_string(va_arg(args, char *)));
    else if (specifier == 'd' || specifier == 'i')
        return (print_number(va_arg(args, int)));
    else if (specifier == 'u')
        return (print_unsigned(va_arg(args, unsigned int)));
    else if (specifier == 'x' || specifier == 'X')
        return (print_hex(va_arg(args, unsigned int), specifier));
    else if (specifier == 'p')
        return (print_pointer((unsigned long long)va_arg(args, void *)));
    else if (specifier == '%')
        return (write(1, "%", 1));
    return (0);
}
void parse_flags(const char *format, int *i, t_format *fmt) { while (format[*i] == '-' || format[*i] == '0' || format[*i] == '#' || format[*i] == '+' || format[*i] == ' ') { if (format[*i] == '-') fmt->minus = 1; if (format[*i] == '0') fmt->zero = 1; if (format[*i] == '#') fmt->hash = 1; if (format[*i] == '+') fmt->plus = 1; if (format[*i] == ' ') fmt->space = 1; (*i)++; }
 }
int ft_printf(const char *format, ...)
{
    va_list args;
    int     i;
    int     count;

    va_start(args, format);
    i = 0;
    count = 0;
    while (format[i])
    {
        if (format[i] == '%' &&
            (format[i+1] == 's' || format[i+1] == 'c' || format[i+1] == 'd' || format[i+1] == 'i' ||
             format[i+1] == 'u' || format[i+1] == 'x' || format[i+1] == 'X' || format[i+1] == 'p'))
        {
            count += specifier_dispatch(format[i+1], args);
            i++;
        }
        else if 
        else
        {
            count += write(1, &format[i], 1);
            i++;
        }
    }
    va_end(args);
    return (count);
}
int main ()
{
    ft_printf("HELLO %s name is " , "AHMED");
    return 0; 
}
// 