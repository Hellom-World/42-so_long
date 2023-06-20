/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:13:34 by heolivei          #+#    #+#             */
/*   Updated: 2022/12/01 11:54:30 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_tocut(const char *s, char c)
{
	size_t	cut;

	cut = 0;
	while (*s)
	{
		if (*s != c)
		{
			++cut;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (cut);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	len;

	i = 0;
	if (!s)
		return (0);
	split = malloc(sizeof(char *) * (ft_tocut(s, c) + 1));
	if (!split)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				s++;
			split[i++] = ft_substr((s - len), 0, len);
		}
		else
			++s;
	}
	split[i] = 0;
	return (split);
}
