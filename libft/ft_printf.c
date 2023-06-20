/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <heolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:28:31 by heolivei          #+#    #+#             */
/*   Updated: 2023/02/07 12:36:09 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_str(char *str)
{
	int	i;
	int	qcp;

	i = 0;
	qcp = 0;
	if (!str)
	{
		ft_print_str("(null)");
		return (6);
	}
	while (str[i])
	{
		qcp += write(1, &str[i], sizeof(char));
		i++;
	}
	return (qcp);
}

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_formats(va_list args, const char format)
{
	int	qcp;

	qcp = 0;
	if (format == 'c')
		qcp += ft_print_char(va_arg(args, int));
	else if (format == 's')
		qcp += ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		qcp += ft_print_pointer(va_arg(args, size_t));
	else if (format == 'd' || format == 'i')
		qcp += ft_print_number(va_arg(args, int));
	else if (format == 'u')
		qcp += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		qcp += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		qcp += ft_print_char('%');
	return (qcp);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		qcp;
	va_list	args;

	i = 0;
	qcp = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			qcp = qcp + ft_formats(args, str[++i]);
			i++;
		}
		else
		{
			qcp = qcp + ft_print_char(str[i]);
			i++;
		}
	}
	va_end(args);
	return (qcp);
}
/*#include <stdio.h>

int main() {
    char c = 'A';
    char s[] = "Hello, World!";
    int i = -10;
    int d = MIN_INT;
    int x = 255;
    int *p = &i;
    unsigned int u = 10;

   ft_printf("Unsigned integer: %u\n", u);
   ft_printf("Pointer: %p\n", (void *)p);
   ft_printf("Character: %c\n", c);
   ft_printf("String: %s\n", s);
   ft_printf("Integer: %i\n", i);
   ft_printf("Decimal: %d\n", d);
   ft_printf("Hexadecimal (lowercase): %x\n", x);
   ft_printf("Hexadecimal (uppercase): %X\n", x);
   ft_printf("Percent sign: %%\n\n");

   printf("Unsigned integer: %u\n", u);
   printf("Pointer: %p\n", (void *)p);
   printf("Character: %c\n", c);
   printf("String: %s\n", s);
   printf("Integer: %i\n", i);
   printf("Decimal: %d\n", d);
   printf("Hexadecimal (lowercase): %x\n", x);
   printf("Hexadecimal (uppercase): %X\n", x);
   printf("Percent sign: %%\n");


    return 0;
}*/
