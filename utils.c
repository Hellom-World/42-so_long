/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 14:31:24 by heolivei          #+#    #+#             */
/*   Updated: 2023/07/02 15:42:44 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin_solong(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	k;

	i = -1;
	k = 0;
	if (!s1)
		s1 = ft_substr("", 0, 0);
	if (!s1 || !s2)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!str)
		return (0);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[k] != '\0')
		str[i++] = s2[k++];
	str[i] = '\0';
	free(s1);
	free(s2);
	return (str);
}

t_lay	ft_new_struct_layout(void)
{
	t_lay	layout;

	layout.n_row = 0;
	layout.n_col = 0;
	layout.n_exit = 0;
	layout.n_person = 0;
	layout.n_collect = 0;
	return (layout);
}

int	ft_strrncmp(const char *s1, const char *s2, size_t n)
{
	size_t		len1;
	size_t		len2;
	const char	*end1;
	const char	*end2;

	len1 = 0;
	len2 = 0;
	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;
	end1 = s1 + len1 - 1;
	end2 = s2 + len2 - 1;
	while (n > 0 && end1 >= s1 && end2 >= s2)
	{
		if (*end1 != *end2)
			break ;
		end1--;
		end2--;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)(*end1) - (unsigned char)(*end2));
}

int	ft_countchar(char *str, char c)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		if (*str == c)
		{
			count++;
		}
		str++;
	}
	return (count);
}

void	ft_free_split(char **split)
{
	int	i;
	i = 0;

	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split[i]);
}
