/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkaterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:50:11 by pkaterin          #+#    #+#             */
/*   Updated: 2021/04/17 22:38:49 by pkaterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *destination, const void *source, int c, size_t n)
{
	unsigned char	*dst;
	unsigned char	*src;
	size_t			i;

	dst = (unsigned char *)destination;
	src = (unsigned char *)source;
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		if (src[i] == (unsigned char) c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
