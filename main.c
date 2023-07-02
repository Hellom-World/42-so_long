/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <heolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:13:11 by heolivei          #+#    #+#             */
/*   Updated: 2023/07/02 14:44:43 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_readlayout(int fd, t_err *map_err, t_lay *lay, char **map_str)
{
	char	*line;
	char	*last_line;

	line = NULL;
	last_line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (!lay->n_col)
				ft_error_filter("Map is empty", NULL);
			else
			{
				ft_checklayout(last_line, map_err, lay, 1);
				free(last_line);
				break ;
			}
		}
		free(last_line);
		ft_checklayout(line, map_err, lay, !lay->n_row);
		last_line = ft_substr(line, 0, ft_strlen(line));
		*map_str = ft_strjoin_solong(*map_str, line);
		lay->n_row++;
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	t_lay	layout;
	char	**map_matrix;

	map_matrix = NULL;
	fd = checker_general_params(argc, argv);
	map_matrix = ft_check_map(fd, &layout);
	int i = 0;
	while (map_matrix[i])
	{
		free(map_matrix[i]);
		i++;
	}
	free(map_matrix[i]);
	free(map_matrix);
	return (0);
}
