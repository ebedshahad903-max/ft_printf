#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

void init_format(t_format *f) {
    f->minus = 0;
    f->zero = 0;
    f->width = 0;
    f->dot = 0;
    f->precision = 0;
    f->hash = 0;
    f->plus = 0;
    f->space = 0;
    f->specifier = 0;
}

void parse_flags(const char *fmt, int *i, t_format *f) {
    while (fmt[*i] == '#' || fmt[*i] == '+') {
        if (fmt[*i] == '#') f->hash = 1;
        if (fmt[*i] == '+') f->plus = 1;
        (*i)++;
    }
}

void parse_width(const char *fmt, int *i, t_format *f) {
    while (fmt[*i] >= '0' && fmt[*i] <= '9') {
        f->width = f->width * 10 + (fmt[*i] - '0');
        (*i)++;
    }
}

void parse_specifier(const char *fmt, int *i, t_format *f) {
    char c = fmt[*i];

    if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%') {
        f->specifier = c;
        (*i)++;
    }
}

int print_char_n(char c, int n) {
    int count = 0;
    while (n-- > 0)
        count += write(1, &c, 1);
    return count;
}

int print_number(long n, t_format *f) {
    char *num = ft_itoa(n); // Assume `ft_itoa` handles integer to string conversion
    int len = ft_strlen(num); // Assume `ft_strlen` is correctly implemented
    int count = 0;
    int is_negative = (n < 0);

    // Handling sign (+ or -)
    if (f->plus && !is_negative)
        count += write(1, "+", 1);
    else if (is_negative)
        count += write(1, "-", 1);

    // Handling alternate form (#)
    if (f->hash && n != 0) {
        if (f->specifier == 'x' || f->specifier == 'X')
            count += write(1, (f->specifier == 'x' ? "0x" : "0X"), 2);
        else if (f->specifier == 'o')
            count += write(1, "0", 1);
    }

    // Print the number
    count += write(1, num, len);

    return count;
}

int print_formatted(t_format *f, va_list *args) {
    if (f->specifier == 'd' || f->specifier == 'i')
        return print_number(va_arg(*args, int), f);
    
    if (f->specifier == '%')
        return write(1, "%", 1);
    
    return 0;
}

int ft_printf(const char *fmt, ...) {
    va_list args;
    int i = 0;
    int count = 0;
    t_format f;

    va_start(args, fmt);

    while (fmt[i]) {
        if (fmt[i] == '%') {
            i++;
            init_format(&f);
            parse_flags(fmt, &i, &f);
            parse_width(fmt, &i, &f); // Optional: width handling can be added if needed
            parse_specifier(fmt, &i, &f);
            count += print_formatted(&f, &args);
        } else {
            count += write(1, &fmt[i++], 1);
        }
    }

    va_end(args);
    return count;
}
// bbbb
int print_pointer(unsigned long n, t_format *f) {
    char *hex = to_hex_ptr(n); // Assume `to_hex_ptr` converts pointer to hex string
    int len = ft_strlen(hex) + 2; // "0x" prefix
    int count = 0;

    if (!f->minus && f->width > len)
        count += print_char_n(' ', f->width - len);