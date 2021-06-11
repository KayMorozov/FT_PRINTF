/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkaterin <pkaterin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:40:11 by pkaterin          #+#    #+#             */
/*   Updated: 2021/04/26 12:35:33 by pkaterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	size_s;

	size_s = ft_strlen(s);
	while (size_s && s[size_s] != (char)c)
		size_s--;
	if (s[size_s] == (char)c)
		return ((char *)(s + size_s));
	return (NULL);
}
