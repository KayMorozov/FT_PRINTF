/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkaterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 20:00:32 by pkaterin          #+#    #+#             */
/*   Updated: 2021/04/17 22:43:52 by pkaterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stddef.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*destination;
	const unsigned char	*source;
	size_t				i;

	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = 0;
	if (src == 0 && dst == 0)
		return (NULL);
	if (!len)
		return (dst);
	if (source < destination)
	{
		while (--len)
			destination[len] = source[len];
		destination[len] = source[len];
		return (dst);
	}
	while (i < len)
	{
		destination[i] = source[i];
		i++;
	}
	return (dst);
}
