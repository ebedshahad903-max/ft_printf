#include "ft_printf.h"
void print_p_flag(unsigned long long mem_address)
{
     printf("\n Hello \n");
    printf("\n in func : %lld \n",mem_address);
    // convert to hex :
    char *hex_number =ft_itoa(mem_address);
    printf("\n the itoa res : %s",hex_number);

}
// char * convert_to_hex(unsigned long long number)
// {
    
// }



static int	ft_numlen(unsigned long long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(unsigned long long n)
{
	char	*str;
	unsigned long long	nb;
	int		len;

	nb = n;
	len = ft_numlen(nb);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	// if (nb < 0)
	// {
	// 	str[0] = '-';
	// 	nb = -nb;
	// }
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
