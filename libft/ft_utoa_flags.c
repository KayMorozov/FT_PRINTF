#include "libft.h"

static int	ft_ilen(unsigned long *num, int tail, int base)
{
	int				len;
	unsigned long	n;

	n = *num;
	len = 1;
	while (n / base != 0)
	{
		n /= base;
		len++;
	}
	if (tail > 2147483646)
		tail = 2147483646;
	if (tail > len)
		len = tail;
	return (len);
}

char	*ft_utoa_flags(unsigned long n, int tail, int flag, int base)
{
	int		i;
	int		len;
	char	*string;

	len = ft_ilen(&n, tail, base);
	if (n < 0 && flag)
		len++;
	string = malloc(sizeof(char) * (len + 1));
	if (!string)
		return (NULL);
	i = 0;
	while (i < len)
		string[i++] = '0';
	string[len] = '\0';
	while (n / base != 0)
	{
		string[--len] = "0123456789abcdef"[n % base];
		n /= base;
	}
	string[--len] = "0123456789abcdef"[n % base];
	return (string);
}
