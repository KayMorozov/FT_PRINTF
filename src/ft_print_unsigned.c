#include "ft_printf.h"

static char	*format_str(unsigned int n, t_flags flags)
{
	int		flag;
	char	*string;

	if (flags.zero && flags.width && !flags.prescision
		&& !flags.dot)
	{
		string = ft_utoa_flags(n, flags.width, 0, 10);
		flag = 0;
	}
	else
	{
		string = ft_utoa_flags(n, flags.prescision, 1, 10);
		flag = 1;
	}
	if (!string)
		return (NULL);
	return (string);
}

int	ft_print_unsigned(t_flags flags, va_list args)
{
	int				char_count;
	char			*string;
	unsigned int	n;

	ft_change_flags(&flags, args);
	n = va_arg(args, unsigned int);
	char_count = 0;
	if (flags.dot && !flags.prescision && !n)
		string = ft_strdup("");
	else
		string = format_str(n, flags);
	if (!string)
		return (-1);
	char_count += ft_print(string, flags);
	free(string);
	return (char_count);
}
