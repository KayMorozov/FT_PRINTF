#include "ft_printf.h"

static int	ft_minus_print(char c, t_flags flags)
{
	int	char_count;

	char_count = 0;
	write(1, &c, 1);
	char_count++;
	flags.width--;
	while (flags.width-- > 0)
		char_count += ft_putchar_fd(' ', 1);
	return (char_count);
}

static	int	ft_print_not_minus(char c, t_flags flags)
{
	int	char_count;
	int	i;

	i = 0;
	char_count = 0;
	flags.width--;
	while (flags.width-- > 0)
		char_count += ft_putchar_fd(' ', 1);
	i = char_count;
	char_count = 0;
	write(1, &c, 1);
	char_count += i + 1;
	return (char_count);
}

static	int	ft_print_c_null(char c, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.minus)
		char_count += ft_minus_print(c, flags);
	else
		char_count += ft_print_not_minus(c, flags);
	return (char_count);
}

int	ft_print_char(t_flags flags, va_list args)
{
	int		char_count;
	char	*chr;
	char	temp;

	char_count = 0;
	ft_change_flags(&flags, args);
	temp = va_arg(args, int);
	if (!temp)
	{
		char_count += ft_print_c_null(temp, flags);
		return (char_count);
	}
	chr = malloc(sizeof (char) * 1 + 1);
	if (!chr)
		return (-1);
	chr[0] = temp;
	chr[1] = '\0';
	char_count += ft_print(chr, flags);
	free(chr);
	return (char_count);
}
