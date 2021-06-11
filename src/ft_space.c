#include "ft_printf.h"

int	ft_space(char c, t_flags *flags)
{
	int	i;

	i = 0;
	if (c == ' ')
		flags -> space = 1;
	return (1);
}
