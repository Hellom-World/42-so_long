/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:37:21 by heolivei          #+#    #+#             */
/*   Updated: 2023/02/07 12:46:16 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_number(int n)
{
	int	qcp;
	int	temp;

	qcp = 0;
	temp = n;
	if (n == MIN_INT)
		return (ft_print_str("-2147483648"));
	if (n < 0)
	{
		ft_print_char('-');
		qcp++;
		temp = -temp;
	}
	if (temp >= 10)
		qcp += ft_print_number(temp / 10);
	ft_print_char((temp % 10) + '0');
	qcp++;
	return (qcp);
}
