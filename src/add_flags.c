#include "ft_printf.h"

int	add_flags(t_flags *flags, char *str)
{
	int	i;

	i = 0;
	while (check_flag_types(str[i], *flags))
	{
		if (str[i] == '0' && flags -> width == 0
			&& flags -> minus == 0 && flags -> prescision == 0)
			i += ft_zero(str[i], flags);
		else if (str[i] == '-')
			i += ft_minus(str[i], flags);
		else if (str[i] == ' ')
			i += ft_space(str[i], flags);
		else if (str[i] == '.')
			i += ft_dot(str[i], flags);
		else if ((str[i] == '*' && flags -> dot == 1)
			|| (ft_isdigit(str[i]) && flags -> dot == 1))
			i += ft_prescision(str + i, flags);
		else if (str[i] == '*' || ft_isdigit(str[i]))
			i += ft_width(str + i, flags);
		else
			flags -> type = str[i++];
	}
	return (i);
}
