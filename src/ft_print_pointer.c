#include "ft_printf.h"
#include <stdio.h>
static char	*format_str(unsigned long n, t_flags flags)
{
	char	*string;

	if (flags.zero && flags.width && !flags.prescision
		&& !flags.dot)
		string = ft_utoa_flags(n, flags.width, 0, 16);
	else
		string = ft_utoa_flags(n, flags.prescision, 1, 16);
	if (!string)
		return (NULL);
	return (string);
}

int	ft_print_pointer(t_flags flags, va_list args)
{
	int				char_count;
	char			*string;
	unsigned long	temp;
	char			*temp_str;

	char_count = 0;
	ft_change_flags(&flags, args);
	temp = (unsigned long)va_arg(args, void *);
	if (flags.dot && !flags.prescision && !temp)
		string = ft_strdup("");
	else
		string = format_str(temp, flags);
	if (!string)
		return (-1);
	temp_str = string;
	string = ft_strjoin("0x", string);
	free(temp_str);
	if (!string)
		return (-1);
	char_count += ft_print(string, flags);
	free(string);
	return (char_count);
}
