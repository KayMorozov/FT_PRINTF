/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkaterin <pkaterin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:27:17 by pkaterin          #+#    #+#             */
/*   Updated: 2021/04/22 20:08:53 by pkaterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	size_num(int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*arr;
	size_t	i;
	size_t	n2;

	i = size_num(n);
	arr = malloc(sizeof(char) * (i + 1));
	if (!arr)
		return (NULL);
	arr[i--] = '\0';
	if (n < 0)
	{
		arr[0] = '-';
		n2 = (size_t)(-(n + 1)) + 1;
	}
	else
		n2 = (size_t)n;
	if (!n)
		arr[0] = '0';
	while (n2)
	{
		arr[i--] = n2 % 10 + '0';
		n2 /= 10;
	}
	return (arr);
}
