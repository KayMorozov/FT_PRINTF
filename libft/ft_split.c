/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkaterin <pkaterin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:07:04 by pkaterin          #+#    #+#             */
/*   Updated: 2021/04/26 14:44:42 by pkaterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_skip(char const *s, char c, size_t i)
{
	while (s[i] == c)
		i++;
	return (i);
}

static	size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	n;
	size_t	flag;

	i = ft_skip(s, c, 0);
	n = 0;
	flag = 0;
	if (s[i])
		n++;
	while (s[i])
	{
		if (s[i] == c)
		{
			flag++;
			i = ft_skip(s, c, i) - 1;
		}
		else if (flag)
		{
			n++;
			flag = 0;
		}
		i++;
	}
	return (n);
}

static	void	ft_free(char **arr)
{
	while (*arr)
	{
		free(*arr);
		arr++;
	}
	free(arr);
}

static	void	kostbIlb(char const *s, char c, char **arr)
{
	size_t	i;
	size_t	j;
	size_t	start;

	start = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		i = ft_skip(s, c, i);
		if (i == ft_strlen(s))
			break ;
		start = i;
		while (s[i] != c && s[i])
			i++;
		arr[j] = ft_substr(s, start, i - start);
		if (!arr[j])
		{
			ft_free(arr);
			return ;
		}
		j++;
	}
	arr[j] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	kostbIlb(s, c, arr);
	if (!arr)
		return (NULL);
	return (arr);
}
