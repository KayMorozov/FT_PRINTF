/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkaterin <pkaterin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:17:56 by pkaterin          #+#    #+#             */
/*   Updated: 2021/04/26 12:37:32 by pkaterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *destination, int c, size_t n)
{
	unsigned char	*arr;
	unsigned char	c_c;

	arr = destination;
	c_c = (unsigned char) c;
	while (n)
		arr[--n] = c_c;
	return (destination);
}
