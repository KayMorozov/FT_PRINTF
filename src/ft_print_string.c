#include "ft_printf.h"

int	ft_print_string(t_flags flags, va_list args)
{
	int		char_count;
	char	*string;
	char	*temp;

	ft_change_flags(&flags, args);
	temp = va_arg(args, char *);
	char_count = 0;
	if (!temp)
		temp = ft_strdup("(null)");
	if (flags.dot && !flags.prescision)
		string = ft_strdup("");
	else
	{
		if (flags.prescision)
			string = ft_substr(temp, 0, flags.prescision);
		else
			string = ft_substr(temp, 0, ft_strlen(temp));
	}
	if (!string)
		return (-1);
	char_count += ft_print(string, flags);
	free(string);
	return (char_count);
}
