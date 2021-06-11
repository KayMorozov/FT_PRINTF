#include "ft_printf.h"

int	ft_dot(char c, t_flags *flags)
{
	if (c == '.')
		flags -> dot = 1;
	return (1);
}
