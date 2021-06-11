#include "ft_printf.h"
#include <stdio.h>
static char	*format_str(t_flags flags)
{
	char	*string;

	if (flags.width && flags.zero)
	{
		string = malloc(sizeof(char) * flags.width + 1);
		if (!string)
			return (NULL);
		string[flags.width] = '\0';
		string[flags.width - 1] = '%';
		flags.width--;
		while (flags.width > 0)
			string[--flags.width] = '0';
	}
	else
	{
		string = malloc(sizeof(char) * 1 + 1);
		if (!string)
			return (NULL);
		string[0] = '%';
		string[1] = '\0';
	}
	return (string);
}

int	ft_print_percent(t_flags flags, va_list args)
{
	int		char_count;
	char	*string;

	ft_change_flags(&flags, args);
	char_count = 0;
	string = format_str(flags);
	if (!string)
		return (-1);
	char_count += ft_print(string, flags);
	free(string);
	return (char_count);
}
