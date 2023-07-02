/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:24:27 by heolivei          #+#    #+#             */
/*   Updated: 2023/01/29 13:43:11 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_pointer(size_t ptr)
{
	int	len;

	if (ptr == 0)
	{
		ft_print_str("(nil)");
		return (5);
	}
	len = ft_print_str("0x");
	len += ft_print_hex(ptr, 'x');
	return (len);
}
