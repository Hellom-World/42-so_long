/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <heolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:13:11 by heolivei          #+#    #+#             */
/*   Updated: 2023/07/15 00:46:45 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

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

int on_destroy(t_game *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int on_keypress(int keysym, t_game *data)
{
	(void)data;
	printf("Pressed key: %d\n", keysym);
	return (0);
}

void	load_assets(t_game *game)
{
	game->texture[0] = mlx_xpm_file_to_image(game->mlx_ptr, "assets/player.xpm", (int *)32, (int *)32);
}

void	load_game(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				(void)game;
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->texture[0], i, j);
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	t_lay	layout;
	t_game	game;
	char	**map_matrix;

	map_matrix = NULL;
	fd = checker_general_params(argc, argv);
	map_matrix = ft_check_map(fd, &layout);

	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		return (printf("error init()"));
	game.win_ptr = mlx_new_window (game.mlx_ptr, layout.n_col * 32 , layout.n_row * 32, "Hellom World");
	if (!game.mlx_ptr)
		return (printf("error win()"));

	// Register key release hook
	mlx_hook(game.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &game);

	// Register destroy hook
	mlx_hook(game.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &game);

	load_game(&game, map_matrix);

	mlx_loop(game.mlx_ptr);

	ft_free_split(map_matrix);
	return (0);
}
