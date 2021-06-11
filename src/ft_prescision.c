#include "ft_printf.h"

int	ft_prescision(char *str, t_flags *flags)
{
	int	i;

	i = 0;
	if (str[i] == '*')
	{
		flags->prescision = -1;
		i = 1;
	}
	else if (ft_isdigit(str[i]))
	{
		while (ft_isdigit(str[i]))
			i++;
		flags->prescision = ft_atoil(str, i);
	}
	return (i);
}
