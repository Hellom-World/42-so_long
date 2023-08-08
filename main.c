/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <heolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:13:11 by heolivei          #+#    #+#             */
/*   Updated: 2023/08/07 19:34:55 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"


t_point	ft_player_position(char **map)
{
	int	y;
	int	x;

	x = 0;
	y = 0;

	while(map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if(map[y][x] == 'P')
				return ((t_point){x, y});
			x++;
		}
		y++;
	}
	return ((t_point){0, 0});
}

char	**ft_copy_matrix(char **map_matrix, t_point size)
{
	char	**tmp_map;
	int	i;
	int	j;

	i = 0;
	tmp_map = malloc(sizeof(char *) * (size.y + 1));
	if(!tmp_map)
		return (NULL);
	while(i < size.y)
	{
		j = 0;
		tmp_map[i] = malloc(sizeof(char) * (size.x + 2));
		if(!tmp_map[i])
			return (NULL);
		while (j <= size.x)
		{
			tmp_map[i][j] = map_matrix[i][j];
			j++;
		}
		tmp_map[i][j] = '\0';
		i++;
	}
	tmp_map[i] = NULL;
	return (tmp_map);
}
void fill(char **tab, t_point size, t_point cur, int count_n_collect, int count_n_exit)
{
    if (tab[cur.y][cur.x] == '1')
        return;
    else if (tab[cur.y][cur.x] == 'C')
        count_n_collect++;
	else if (tab[cur.y][cur.x] == 'E')
        count_n_exit++;
    tab[cur.y][cur.x] = '1';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, count_n_collect, count_n_exit);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, count_n_collect, count_n_exit);
    fill(tab, size, (t_point){cur.x, cur.y - 1}, count_n_collect, count_n_exit);
    fill(tab, size, (t_point){cur.x, cur.y + 1}, count_n_collect, count_n_exit);
}
void  flood_fill(char **tab, t_point size, t_point begin, t_lay lay)
{
	static int count_n_collect;
	static int count_n_exit;
	int	x = -1;
    fill(tab, size, begin, count_n_collect, count_n_exit);
	while (tab[++x])
		printf("%s\n", tab[x]);
	printf("struct n_collet %d ", lay.n_collect );
	printf("count_n_collet %d\n", count_n_collect );
	printf("struct n_exit %d ", lay.n_exit );
	printf("count_n_collet %d\n", count_n_exit );
	if(count_n_collect != lay.n_collect || count_n_exit != lay.n_exit)
		ft_error_filter("Invalid map", 0);
}

void	ft_check_path(char **tmp_map, t_lay *lay)
{
	t_point	begin;
	t_point size;
	int	x;

	x = -1;
	begin = ft_player_position(tmp_map);
	size = (t_point){lay->n_col, lay->n_row};
	flood_fill(tmp_map, size, begin, *lay);

	while (tmp_map[++x])
		printf("%s\n", tmp_map[x]);
	ft_free_split(tmp_map);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_lay	layout;
	char	**map_matrix;

	map_matrix = NULL;
	fd = checker_general_params(argc, argv);
	map_matrix = ft_check_map(fd, &layout);
	printf("\n\n");
	ft_check_path(ft_copy_matrix(map_matrix, (t_point){layout.n_col, layout.n_row}), &layout);
	game_init(map_matrix, &layout);
	return (0);
}
