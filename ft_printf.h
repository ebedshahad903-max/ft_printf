#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_format 
{ 
    int minus;
    int zero; 
    int width; 
    int dot; 
    int precision; 
    int hash; 
    int plus; 
    int space; 
    char specifier;
 } t_format;
int     ft_printf(const char *format, ...);

int     print_char(int c);
int     print_string(char *s);
int     print_number(int n);
int     print_unsigned(unsigned int n);
int     print_hex(unsigned int n, char format);
int     print_pointer(unsigned long long ptr);

#endif
