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
	int width = 42;
	int height = 42;

	game->texture[0] = mlx_xpm_file_to_image(game->mlx_ptr, "textures/floor.xpm", &width, &height);
	game->texture[1] = mlx_xpm_file_to_image(game->mlx_ptr, "textures/player.xpm", &width, &height);
	game->texture[2] = mlx_xpm_file_to_image(game->mlx_ptr, "textures/wall.xpm", &width, &height);
	game->texture[3] = mlx_xpm_file_to_image(game->mlx_ptr, "textures/colet.xpm", &width, &height);
	game->texture[4] = mlx_xpm_file_to_image(game->mlx_ptr, "textures/door_off.xpm", &width, &height);

	ft_printf("%p\n", game->texture[0]);
}

void	load_game(t_game *game, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->texture[1], y * 42, x * 42);
			else if (map[x][y] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->texture[2], y * 42, x * 42);
			else if (map[x][y] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->texture[3], y * 42, x * 42);
			else if (map[x][y] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->texture[4], y * 42, x * 42);
			else
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->texture[0], y * 42, x * 42);
			y++;
		}
		x++;
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

	game.win_ptr = mlx_new_window (game.mlx_ptr, layout.n_col * 42 , layout.n_row * 42, "Hellom World");
	if (!game.mlx_ptr)
		return (printf("error win()"));

	// Register key release hook
	mlx_hook(game.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &game);

	// Register destroy hook
	mlx_hook(game.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &game);

	load_assets(&game);

	load_game(&game, map_matrix);

	mlx_loop(game.mlx_ptr);

	ft_free_split(map_matrix);
	return (0);
}
