#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_flags
{
	int			type;
	int			width;
	int			minus;
	int			zero;
	int			prescision;
	int			space;
	int			dot;
}				t_flags;

int		ft_printf(const char *input, ...);
t_flags	flag_init(void);
int		add_flags(t_flags *flags, char *str);
int		check_flag_types(char c, t_flags flags);
int		ft_zero(char c, t_flags *flags);
int		ft_space(char c, t_flags *flags);
int		ft_minus(char c, t_flags *flags);
int		ft_dot(char c, t_flags *flags);
int		ft_prescision(char *str, t_flags *flags);
int		ft_width(char *str, t_flags *flags);
int		flag_to_string(t_flags flags, va_list args);
void	ft_change_flags(t_flags *flags, va_list args);
int		ft_print_decimal(t_flags flags, va_list args);
int		ft_print(char *str, t_flags flags);
int		ft_print_unsigned(t_flags flags, va_list args);
int		ft_print_string(t_flags flags, va_list args);
int		ft_print_char(t_flags flags, va_list args);
int		ft_print_pointer(t_flags flags, va_list args);
int		ft_print_hex(t_flags flags, va_list args);
int		ft_print_percent(t_flags flags, va_list args);

#endif
