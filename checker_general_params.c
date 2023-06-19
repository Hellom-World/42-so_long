/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_general_params.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:19:55 by heolivei          #+#    #+#             */
/*   Updated: 2023/06/19 19:43:04 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

int	checker_general_params(int argc, char *argv)
{
	int fd;

	if (argc != 2)
	{
		write(1, "Error_args", 10);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error_fd", 8);
		return (0);
	}
	if (!strrncmp(argv[1], ".ber", 4)
	{
		write(1, "Error_.ber", 10);
		return (0);
	}
	return (fd);
}
