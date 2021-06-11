#include "ft_printf.h"

t_flags	flag_init(void)
{
	t_flags	flags;

	flags.type = 0;
	flags.width = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.prescision = 0;
	flags.space = 0;
	flags.dot = 0;
	return (flags);
}
