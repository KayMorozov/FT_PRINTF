#include "ft_printf.h"

int	ft_minus(char c, t_flags *flags)
{
	if (c == '-')
		flags -> minus = 1;
	return (1);
}
