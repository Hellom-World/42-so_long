/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <heolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:13:11 by heolivei          #+#    #+#             */
/*   Updated: 2023/08/05 09:37:26 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_lay	layout;
	char	**map_matrix;

	map_matrix = NULL;
	fd = checker_general_params(argc, argv);
	map_matrix = ft_check_map(fd, &layout);
	game_init(map_matrix, &layout);
	return (0);
}
