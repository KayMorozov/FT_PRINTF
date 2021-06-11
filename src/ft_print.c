#include "ft_printf.h"

static int	ft_minus_print(char *str, t_flags flags, int len)
{
	int	char_count;

	char_count = 0;
	while (char_count < len)
	{
		write(1, str + char_count++, 1);
		flags.width--;
	}
	while (flags.width-- > 0)
		char_count += ft_putchar_fd(' ', 1);
	return (char_count);
}

static	int	ft_print_not_minus(char *str, t_flags flags, int len)
{
	int	char_count;
	int	i;

	char_count = 0;
	flags.width -= len;
	while (flags.width-- > 0)
		char_count += ft_putchar_fd(' ', 1);
	i = char_count;
	char_count = 0;
	while (char_count < len)
		write(1, str + char_count++, 1);
	char_count += i;
	return (char_count);
}

int	ft_print(char *str, t_flags flags)
{
	int	char_count;
	int	len;

	char_count = 0;
	if (str == NULL)
		return (ft_print("(null)", flags));
	len = ft_strlen(str);
	if (flags.minus)
		char_count += ft_minus_print(str, flags, len);
	else
		char_count += ft_print_not_minus(str, flags, len);
	return (char_count);
}
