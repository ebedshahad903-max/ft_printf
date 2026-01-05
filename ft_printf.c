#include "ft_printf.h"

static int  dispatch(char specifier, va_list args)
{
    if (specifier == 'c')
        return (print_char(va_arg(args, int)));
    // if (specifier == 's')
    //     return (print_string(va_arg(args, char *)));
    // if (specifier == 'd' || specifier == 'i')
    //     return (print_number(va_arg(args, int)));
    // if (specifier == 'u')
    //     return (print_unsigned(va_arg(args, unsigned int)));
    // if (specifier == 'x' || specifier == 'X')
    //     return (print_hex(va_arg(args, unsigned int), specifier));
    if (specifier == 'p')
        return (print_pointer((unsigned long long)va_arg(args, void *)));
    if (specifier == '%')
        return (write(1, "%", 1));
    return (0);
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
        if (format[i] == '%')
        {
            count += dispatch(format[i + 1], args);
            i++;
        }
        else
            count += write(1, &format[i], 1);
        i++;
    }
    va_end(args);
    return (count);
}
#include <stdio.h>
int main()
{
   // int res1;
    // printf("|||||||||||||||||||||||||||||||||||||||||||||||||\n");
    // printf ("First Testcase : Pure string \n");
    //  printf ("with escape seq : \\t , \\n ,\\v ,\\ooo ,\\f,\\ \n");
    // int res1 =printf ("shahd1\tshahad2\t");
    // printf("len1 = %d\n",res1);
    // int res2= ft_printf("shahd1\tshahad2\t");
    // printf("len2 = %d",res2);
    // printf("|||||||||||||||||||||||||||||||||||||||||||||||||\n");
    // printf ("sec Testcase : print a char \n");
    // char letter = 'Q';
    // res1=printf("%c",letter);
    // printf("len1 = %d\n",res1);
    // res2=ft_printf("%c",letter);
    // printf("len2 = %d\n",res2);
    // //------------------------------------------//
    // char n ='N';
    //  res1=printf("Hello %c How are you%c ?",letter,n);
    // printf("len1 = %d\n",res1);
    // res2=ft_printf("Hello %c How are you%c ?",letter,n);
    // printf("len2 = %d\n",res2);
    printf("-------------------------------------------------------------------------\n");
   // printf ("Third  Testcase :p:: The void * pointer argument has to be printed in hexadecimal format. \n");
    int m = 30;
    //int *ptr = &m; // pointer to x
//printf("Value of x: %d\n", m);
   //printf("%p\n",(void *) ptr);
  // printf("\nlen1 = %d\n",res1);
   //ft_printf("%p",(void *) ptr);
    
   
   printf("\n ORIG : \t [%p]\n\n");
   ft_printf("\n NEWW : \t [%p]\n\n");
   return 0;
}