#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
void	ft_putstr_fd(char *s, int fd)
{
	size_t	len ;

	len = ft_strlen(s);
	write (fd, s, len);
}
