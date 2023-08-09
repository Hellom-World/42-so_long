#include "./so_long.h"


t_point	ft_position(char **map, char c)
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
			if(map[y][x] == c)
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
void fill(char **tab, t_point size, t_point cur, t_point *n_exit_and_collect)
{
    if (tab[cur.y][cur.x] == '1')
        return;
    else if (tab[cur.y][cur.x] == 'C')
        n_exit_and_collect->x++;
	else if (tab[cur.y][cur.x] == 'E')
        n_exit_and_collect->y++;
    tab[cur.y][cur.x] = '1';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, n_exit_and_collect);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, n_exit_and_collect);
    fill(tab, size, (t_point){cur.x, cur.y - 1}, n_exit_and_collect);
    fill(tab, size, (t_point){cur.x, cur.y + 1}, n_exit_and_collect);
}
void  flood_fill(char **tab, t_point size, t_point begin, t_lay lay)
{
	t_point	n_exit_and_collect;
	int	x = -1;

	n_exit_and_collect.x = 0;
	n_exit_and_collect.y = 0;

	x = -1;
    fill(tab, size, begin, &n_exit_and_collect);
	while (tab[++x])
		ft_printf("%s\n", tab[x]);
	if(n_exit_and_collect.x != lay.n_collect || n_exit_and_collect.y != lay.n_exit)
		ft_error_filter("Invalid map", 0);
}

void	ft_check_path(char **tmp_map, t_lay *lay)
{
	t_point	p_position;
	t_point size;
	int	x;

	x = -1;
	p_position = ft_position(tmp_map, 'P');
	size = (t_point){lay->n_col, lay->n_row};
	flood_fill(tmp_map, size, p_position, *lay);

	while (tmp_map[++x])
		printf("%s\n", tmp_map[x]);
	ft_free_split(tmp_map);
}
