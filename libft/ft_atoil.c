/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkaterin <pkaterin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:01:05 by pkaterin          #+#    #+#             */
/*   Updated: 2021/04/21 14:49:21 by pkaterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoil(const char *str, int len)
{
	int		i;
	int		flag_sign;
	int		rez;

	i = 0;
	flag_sign = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag_sign++;
		i++;
	}
	rez = 0;
	while (str[i] >= 48 && str[i] <= 57 && i <= len)
		rez = rez * 10 + str[i++] - '0';
	if (flag_sign)
		return (-rez);
	return (rez);
}
