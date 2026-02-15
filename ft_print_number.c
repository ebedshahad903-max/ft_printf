#include "ft_printf.h"
//4567 -> n/10 = 456 /)7 
// 
static int  putnbr(long n)
{
    int count = 0;

    if (n < 0)
    {
        count += write(1, "-", 1);
        n = -n;
    }
    if (n >= 10)
        count += putnbr(n / 10);//: 4567 -> 456-> 45 ->4 

    count+= print_char((n % 10) + '0');//: 4567 %10 = = 7 +0 '7'
    return (count);
}

int print_number(int n)
{
    return (putnbr((long)n));
}
int main ()

{
    int a =10;
    char b = 30;
    write
    return 0;
}