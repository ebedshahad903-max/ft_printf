// #include "ft_printf.h"

// static int  dispatch(char specifier, va_list args)
// {
//     if (specifier == 'c')
//         return (print_char(va_arg(args, int)));
//     else if (specifier == 's')
//         return (print_string(va_arg(args, char *)));
//     else if (specifier == 'd' || specifier == 'i')
//         return (print_number(va_arg(args, int)));
//     else if (specifier == 'u')
//         return (print_unsigned(va_arg(args, unsigned int)));
//     else if (specifier == 'x' || specifier == 'X')
//         return (print_hex(va_arg(args, unsigned int), specifier));
//     else if (specifier == 'p')
//         return (print_pointer((unsigned long long)va_arg(args, void *)));
//     else if (specifier == '%')
//         return (write(1, "%", 1));
//     return (0);
// }

// int ft_printf(const char *format, ...)
// {
//     va_list args;
//     int     i;
//     int     count;

//     va_start(args, format);
//     i = 0;
//     count = 0;
//     while (format[i])
//     {
//         if (format[i] == '%')
//         {
//             count += dispatch(format[i + 1], args);
//             i++;
//         }
//         else
//         {
//             count += write(1, &format[i], 1);
//             i++;
//         }
//     }
//     va_end(args);
//     return (count);
// }
// // 