#include "ft_printf.h"

int	check_flag_types(char c, t_flags flags)
{
	if (!ft_isdigit(c) && c != '*'
		&& c != '.' && c != '%'
		&& c != 'd' && c != 'i'
		&& c != 'u' && c != 'c'
		&& c != 's' && c != 'p'
		&& c != 'x' && c != 'X'
		&& c != '-' && c != ' ')
		return (0);
	if (flags.type != 0)
		return (0);
	return (1);
}
