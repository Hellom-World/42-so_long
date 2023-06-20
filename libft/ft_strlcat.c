/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:29:14 by heolivei          #+#    #+#             */
/*   Updated: 2022/12/01 14:54:57 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	if (size == 0)
		return (ft_strlen(src));
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	j = dst_len;
	i = 0;
	if (size < dst_len)
		return (size + src_len);
	while (src[i] && j < (size - 1))
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = 0;
	return (dst_len + src_len);
}
