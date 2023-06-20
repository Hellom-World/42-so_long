/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <heolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:58:13 by heolivei          #+#    #+#             */
/*   Updated: 2023/02/01 20:49:15 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_unsigned(unsigned int n)
{
	int				count;
	unsigned int	div;
	int				digit;

	digit = 0;
	div = 1;
	count = 0;
	while (n / div >= 10)
	{
		div *= 10;
	}
	while (div > 0)
	{
		digit = n / div % 10;
		ft_print_char(digit + '0');
		count++;
		div /= 10;
	}
	return (count);
}
