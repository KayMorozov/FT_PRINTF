/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkaterin <pkaterin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 20:33:40 by pkaterin          #+#    #+#             */
/*   Updated: 2021/04/23 18:53:48 by pkaterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	i;

	i = 0;
	if (n / 10)
		i += ft_putnbr_fd(n / 10, fd);
	else
		if (n < 0)
			i += ft_putchar_fd('-', fd);
	if (n < 0)
		i += ft_putchar_fd(-(n % 10) + '0', fd);
	else
		i += ft_putchar_fd(n % 10 + '0', fd);
	return (i);
}
