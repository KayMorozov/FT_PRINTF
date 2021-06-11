#include "ft_printf.h"

int	ft_zero(char c, t_flags *flags)
{
	if (c == '0')
		flags -> zero = 1;
	return (1);
}
