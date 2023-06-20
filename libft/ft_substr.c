/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:52:20 by heolivei          #+#    #+#             */
/*   Updated: 2022/11/20 14:19:05 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include "stdio.h"*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (s == 0)
		return (0);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == 0)
		return (0);
	i = (size_t)start;
	j = 0;
	while (j < len && i < ft_strlen(s))
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

/*int main(void)
{
    char src[31] = "substr function Implementation";

    int start = 7;
    int len = 12;

    char* dest = ft_substr(src, start, len);

    printf("%s\n", dest);

    return 0;
}*/
