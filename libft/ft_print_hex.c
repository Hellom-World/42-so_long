/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <heolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:22:54 by heolivei          #+#    #+#             */
/*   Updated: 2023/02/07 12:40:17 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hex_len(size_t n)
{
	size_t	len;

	len = 1;
	while (n > 15)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

int	ft_print_hex(size_t n, char c)
{
	size_t	len;

	len = ft_hex_len(n);
	if (n > 15)
	{
		ft_print_hex(n / 16, c);
		ft_print_hex(n % 16, c);
	}
	else
	{
		if (c == 'x')
			ft_print_char(BASE_LOWER[n]);
		else
			ft_print_char(BASE_UPPER[n]);
	}
	return (len);
}
