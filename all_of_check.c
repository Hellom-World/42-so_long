/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_of_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:46:24 by heolivei          #+#    #+#             */
/*   Updated: 2023/07/02 15:41:30 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_checklayout(char *line, t_err *map_err, t_lay *lay, int is_last)
{
	if (!lay->n_col)
		lay->n_col = (ft_strlen_gnl(line) - 1);
	if (lay->n_col && ((lay->n_col != (int)ft_strlen_gnl(line)
				&& !ft_strchr_gnl(line, '\n'))
			|| (lay->n_col != (int)ft_strlen_gnl(line) - 1
				&& ft_strchr_gnl(line, '\n'))))
		map_err->inv_rowlen = 1;
	if (map_err->inv_rowlen == 0)
	{
		if ((line[0] != '1' || (line[lay->n_col - 1] != '1')
				|| (ft_countchar(line, '1') != lay->n_col && is_last)))
			map_err->inv_borders = 1;
	}
	lay->n_exit += ft_countchar(line, 'E');
	lay->n_person += ft_countchar(line, 'P');
	lay->n_collect += ft_countchar(line, 'C');
	map_err->inv_n_exits = lay->n_exit < 1;
	map_err->inv_n_persons = lay->n_person < 1;
	map_err->inv_n_collect = lay->n_collect < 1;
	while (line && *line)
	{
		if (!ft_strchr_gnl("01CEP\n", *line))
			map_err->inv_char = 1;
		line++;
	}
}

int	checker_general_params(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		ft_error_filter("Only 2 Arguments -> ./so_long map.ber", NULL);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_error_filter("Error opening the file .ber", NULL);
		return (0);
	}
	if (ft_strrncmp(argv[1], ".ber", 4) != 0)
	{
		ft_error_filter("The map file needs to be .ber", NULL);
		return (0);
	}
	return (fd);
}

char	**ft_check_map(int fd, t_lay *layout)
{
	char	*map_str;
	char	**map_matrix;
	t_err	map_err;

	map_str = ft_substr("", 0, 0);
	map_matrix = NULL;
	map_err = ft_new_struct_map_error();
	*layout = ft_new_struct_layout();
	ft_readlayout(fd, &map_err, layout, &map_str);
	//ft_printf("%s", map_str);
	ft_check_error(&map_err, &map_str);
	map_matrix = ft_split(map_str, '\n');
	free(map_str);
	return (map_matrix);
}
