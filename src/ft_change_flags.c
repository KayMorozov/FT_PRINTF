#include "ft_printf.h"

void	ft_change_flags(t_flags *flags, va_list args)
{
	int	temp;

	if (flags -> width < 0)
	{
		temp = va_arg(args, int);
		if (temp < 0)
		{
			flags -> width = -temp;
			flags -> zero = 0;
			flags -> minus = 1;
		}
		else
			flags -> width = temp;
	}
	if (flags -> dot && flags -> prescision < 0)
	{
		temp = va_arg(args, int);
		if (temp < 0)
		{
			flags -> prescision = 0;
			flags -> dot = 0;
		}
		else
			flags -> prescision = temp;
	}
}
