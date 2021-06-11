#include "ft_printf.h"

static char	*check_space(int n, t_flags flags, char *string, int flag)
{
	char	*str_formated;
	char	*space;

	space = " ";
	str_formated = "";
	if (n >= 0 && flags.space)
	{
		if (!flag)
		{
			str_formated = ft_strdup(string);
			if (!str_formated)
				return (NULL);
			str_formated[0] = ' ';
		}
		else
		{
			str_formated = ft_strjoin(space, string);
			if (!str_formated)
				return (NULL);
		}
		free(string);
		return (str_formated);
	}
	return (string);
}

static char	*format_str(int n, t_flags flags)
{
	int		flag;
	char	*string;

	if (flags.zero && flags.width && !flags.prescision
		&& !flags.dot)
	{
		string = ft_itoa_flags(n, flags.width, 0);
		flag = 0;
	}
	else
	{
		string = ft_itoa_flags(n, flags.prescision, 1);
		flag = 1;
	}
	if (!string)
		return (NULL);
	string = check_space(n, flags, string, flag);
	return (string);
}

int	ft_print_decimal(t_flags flags, va_list args)
{
	int		char_count;
	char	*string;
	int		n;

	ft_change_flags(&flags, args);
	n = va_arg(args, int);
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
