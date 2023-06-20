/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 09:37:31 by heolivei          #+#    #+#             */
/*   Updated: 2022/11/20 11:39:23 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelement, size_t size)
{
	size_t	full_size;
	void	*result;

	full_size = size * nelement;
	result = malloc(full_size);
	if (!result)
		return (0);
	ft_memset(result, 0, full_size);
	return (result);
}
