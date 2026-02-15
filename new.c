#include "ft_printf.h"

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
    while (fmt[*i] == '-' || fmt[*i] == '0' || fmt[*i] == '#' || fmt[*i] == '+' || fmt[*i] == ' ') {
        if (fmt[*i] == '-') f->minus = 1;
        if (fmt[*i] == '0') f->zero = 1;
        if (fmt[*i] == '#') f->hash = 1;
        if (fmt[*i] == '+') f->plus = 1;
        if (fmt[*i] == ' ') f->space = 1;
        (*i)++;
    }
}

void parse_width(const char *fmt, int *i, t_format *f) {
    while (fmt[*i] >= '0' && fmt[*i] <= '9') {
        f->width = f->width * 10 + (fmt[*i] - '0');
        (*i)++;
    }
}

void parse_precision(const char *fmt, int *i, t_format *f) {
    if (fmt[*i] == '.') {
        f->dot = 1;
        (*i)++;
        while (fmt[*i] >= '0' && fmt[*i] <= '9') {
            f->precision = f->precision * 10 + (fmt[*i] - '0');
            (*i)++;
        }
    }
}

void parse_specifier(const char *fmt, int *i, t_format *f) {
    char c = fmt[*i];

    if (c == 'c' || c == 's' || c == 'p' ||
        c == 'd' || c == 'i' || c == 'u' ||
        c == 'x' || c == 'X' || c == '%') {
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

int print_number_bonus(long n, t_format *f) {
    char *num = ft_itoa(n);
    int len = ft_strlen(num);
    int count = 0;
    int is_negative = (n < 0);

    if (is_negative) {
        num++;
        len--;
    }

    if (f->dot)
        f->zero = 0;

    if (f->plus && !is_negative)
        count += write(1, "+", 1);
    else if (f->space && !is_negative)
        count += write(1, " ", 1);
    else if (is_negative)
        count += write(1, "-", 1);

    if (f->precision > len)
        count += print_char_n('0', f->precision - len);

    if (!f->minus && f->width > len)
        count += print_char_n(f->zero ? '0' : ' ', f->width - len);

    count += write(1, num, len);

    if (f->minus && f->width > len)
        count += print_char_n(' ', f->width - len);

    return count;
}

int print_hex_bonus(unsigned int n, t_format *f, int upper) {
    char *hex = to_hex(n, upper);
    int len = ft_strlen(hex);
    int count = 0;

    if (f->hash && n != 0)
        count += write(1, upper ? "0X" : "0x", 2);

    if (!f->minus && f->width > len)
        count += print_char_n(f->zero ? '0' : ' ', f->width - len);

    count += write(1, hex, len);

    if (f->minus && f->width > len)
        count += print_char_n(' ', f->width - len);

    return count;
}

int print_string_bonus(char *s, t_format *f) {
    int len = ft_strlen(s);
    int count = 0;

    if (f->dot && f->precision < len)
        len = f->precision;

    if (!f->minus && f->width > len)
        count += print_char_n(' ', f->width - len);

    count += write(1, s, len);

    if (f->minus && f->width > len)
        count += print_char_n(' ', f->width - len);

    return count;
}

int print_pointer_bonus(unsigned long n, t_format *f) {
    char *hex = to_hex_ptr(n);
    int len = ft_strlen(hex) + 2;
    int count = 0;

    if (!f->minus && f->width > len)
        count += print_char_n(' ', f->width - len);

    count += write(1, "0x", 2);
    count += write(1, hex, ft_strlen(hex));

    if (f->minus && f->width > len)
        count += print_char_n(' ', f->width - len);

    return count;
}

int print_formatted(t_format *f, va_list *args) {
    if (f->specifier == 's')
        return print_string_bonus(va_arg(*args, char *), f);

    if (f->specifier == 'd' || f->specifier == 'i')
        return print_number_bonus(va_arg(*args, int), f);

    if (f->specifier == 'u')
        return print_number_bonus(va_arg(*args, unsigned int), f);

    if (f->specifier == 'x')
        return print_hex_bonus(va_arg(*args, unsigned int), f, 0);

    if (f->specifier == 'X')
        return print_hex_bonus(va_arg(*args, unsigned int), f, 1);

    if (f->specifier == 'p')
        return print_pointer_bonus(va_arg(*args, unsigned long), f);

    if (f->specifier == 'c')
        return write(1, &(char){va_arg(*args, int)}, 1);

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
            parse_width(fmt, &i, &f);
            parse_precision(fmt, &i, &f);
            parse_specifier(fmt, &i, &f);
            count += print_formatted(&f, &args);
        } else {
            count += write(1, &fmt[i++], 1);
        }
    }

    va_end(args);
    return count;
}
