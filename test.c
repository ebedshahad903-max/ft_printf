#include "ft_printf.h"
#include<stdarg.h>
#include<unistd.h>
#include<stdio.h>
int divider ()
{
    
}
int ft_printf(const char *str,...)
{
    int index =0;
    va_list arguemnts;
    va_start(arguemnts,str);
    size_t	len ;
    int temp ; 
    len = strlen(str);
    while (str[index]!= '\0')
    {
        if (str[index]=='%')
        {
            if(str[index+1]=='c')// for a char 
            {
                temp = va_arg(arguemnts,int)+0;
                ft_putchar_fd(temp,1);
                index++;// to move from what we have after "%"
                len--;// only one letter
            }
            else if(str[index]=='%'&&(str[index+1]=='s'))
             {
                // need to be checked 
                str1 =va_arg(arg,char*);
                ft_putstr_fd(str1, 1);
                // i need str len to know the last return value 
             }
            else if(str[index+1]=='p')// for a char 
            {
              print_p_flag((unsigned long long )va_arg(arguemnts,void*));
                index++;// to move from what we have after "%"
                len--;// only one letter
            }
        }
        else 
        {
            temp = str[index]+0;
	        write (1,&temp,1);
        }
        
        index++;
    }
 return len;
}
int main()
{
    int res1;
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
    printf ("Third  Testcase :p:: The void * pointer argument has to be printed in hexadecimal format. \n");
    int m = 30;
    int *ptr = &m; // pointer to x
    printf("Value of x: %d\n", m);
   res1= printf("%p",(void *) ptr);
   printf("\nlen1 = %d\n",res1);
   ft_printf("%p",(void *) ptr);
    return 0;
}