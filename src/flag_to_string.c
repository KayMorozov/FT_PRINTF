#include "ft_printf.h"

int	flag_to_string(t_flags flags, va_list args)
{
	int	char_count;

	char_count = 0;
	if (flags.type == 'd' || flags.type == 'i')
		char_count += ft_print_decimal(flags, args);
	if (flags.type == 'u')
		char_count += ft_print_unsigned(flags, args);
	if (flags.type == 's')
		char_count += ft_print_string(flags, args);
	if (flags.type == 'c')
		char_count += ft_print_char(flags, args);
	if (flags.type == 'x' || flags.type == 'X')
		char_count += ft_print_hex(flags, args);
	if (flags.type == 'p')
		char_count += ft_print_pointer(flags, args);
	if (flags.type == '%')
		char_count += ft_print_percent(flags, args);
	if (char_count < 0)
		return (-1);
	return (char_count);
}
