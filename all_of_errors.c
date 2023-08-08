/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_of_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <heolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:47:04 by heolivei          #+#    #+#             */
/*   Updated: 2023/08/07 19:35:20 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error_filter(char *msg, char **matrix)
{
	if (matrix)
		free(*matrix);
	ft_printf("Error\n%s\n", msg);
	exit(0);
	return (0);
}

t_err	ft_new_struct_map_error(void)
{
	t_err	error;

	error.inv_rowlen = 0;
	error.inv_borders = 0;
	error.inv_char = 0;
	error.inv_n_persons = 0;
	error.inv_n_collect = 0;
	error.inv_n_exits = 0;
	return (error);
}

int	ft_check_error(t_err *map_err, char **map_str)
{
	if (map_err->inv_rowlen)
		ft_error_filter("The map is not rectangular!", map_str);
	if (map_err->inv_borders)
		ft_error_filter("Invalid map periphery/borders!", map_str);
	if (map_err->inv_char)
		ft_error_filter("Invalid character in map!", map_str);
	if (map_err->inv_n_exits)
		ft_error_filter("Invalid numbers of exits!", map_str);
	if (map_err->inv_n_persons)
		ft_error_filter("Invalid numbers of players!", map_str);
	if (map_err->inv_n_collect)
		ft_error_filter("Invalid numbers of collectibles!", map_str);
	return (0);
}

