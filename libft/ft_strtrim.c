/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkaterin <pkaterin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:53:20 by pkaterin          #+#    #+#             */
/*   Updated: 2021/04/23 19:58:53 by pkaterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	find_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	tmp;

	i = 0;
	while (s1[i])
	{
		j = 0;
		tmp = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				tmp++;
				break ;
			}
			j++;
		}
		if (!tmp)
			return (i);
		i += tmp;
	}
	return (i);
}

static	size_t	find_end(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	n;
	size_t	tmp;

	i = ft_strlen(s1) - 1;
	n = 0;
	while (s1[n])
	{
		j = 0;
		tmp = 0;
		while (set[j])
		{
			if (s1[i] == set[j++])
			{
				tmp++;
				break ;
			}
		}
		if (!tmp)
			return (i);
		i -= tmp;
		n += tmp;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*arr;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	start = find_start(s1, set);
	end = find_end(s1, set);
	if (end < start)
		return (NULL);
	arr = ft_substr(s1, start, end - start + 1);
	return (arr);
}
