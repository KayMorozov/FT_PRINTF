/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkaterin <pkaterin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:06:40 by pkaterin          #+#    #+#             */
/*   Updated: 2021/04/23 20:14:04 by pkaterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	count_to_set;

	i = 0;
	if (ft_strlen(dst) >= dstsize)
		return (ft_strlen(src) + dstsize);
	j = ft_strlen(dst);
	count_to_set = dstsize - ft_strlen(dst) - 1;
	while (i < count_to_set && src[i])
	{
		dst[i + j] = src[i];
		i++;
	}
	dst[i + j] = '\0';
	return (ft_strlen(dst) + ft_strlen(src) - i);
}
