#include "ft_printf.h"

int	print_result(char *str, va_list args)
{
	int		i;
	int		char_count;
	t_flags	flags;

	i = 0;
	char_count = 0;
	while (str[i])
	{
		flags = flag_init();
		if (str[i] == '%' && str[i + 1])
		{
			i += add_flags(&flags, str + i + 1);
			char_count += flag_to_string(flags, args);
			if (char_count < 0)
				return (-1);
		}
		else if (str[i] != '%')
			char_count += ft_putchar_fd(str[i], 1);
		i++;
	}
	return (char_count);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	char	*input_string;
	int		char_count;

	input_string = ft_strdup(input);
	if (!input_string)
		return (-1);
	va_start(args, input);
	char_count = print_result(input_string, args);
	va_end(args);
	free(input_string);
	return (char_count);
}
