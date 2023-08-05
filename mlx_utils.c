/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:31:34 by heolivei          #+#    #+#             */
/*   Updated: 2023/08/05 18:31:50 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_game *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	on_keypress(int keysym, t_game *data)
{
	(void)data;
	printf("Pressed key: %d\n", keysym);
	return (0);
}

void	load_assets(t_game *game)
{
	int	width;
	int	height;

	width = 42;
	height = 42;
	game->texture[0] = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/floor.xpm", &width, &height);
	game->texture[1] = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/player.xpm", &width, &height);
	game->texture[2] = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/wall.xpm", &width, &height);
	game->texture[3] = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/colet.xpm", &width, &height);
	game->texture[4] = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/door_off.xpm", &width, &height);
	ft_printf("%p\n", game->texture[0]);
}

void	load_game(t_game *game, char **map)
{
	int	x;
	int	y;

	x = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->texture[0], y * 42, x * 42);
			if (map[x][y] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->texture[1], y * 42, x * 42);
			else if (map[x][y] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->texture[2], y * 42, x * 42);
			else if (map[x][y] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->texture[3], y * 42, x * 42);
			else if (map[x][y] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->texture[4], y * 42, x * 42);
		}
	}
}

void	game_init(char **map_matrix, t_lay *layout)
{
	t_game	game;

	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		printf("error init()");
	game.win_ptr = mlx_new_window (game.mlx_ptr, layout->n_col * 42,
			layout->n_row * 42, "Sobradinho");
	if (!game.mlx_ptr)
		printf("error win()");
	mlx_hook(game.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &game);
	mlx_hook(game.win_ptr, DestroyNotify, StructureNotifyMask,
		&on_destroy, &game);
	load_assets(&game);
	load_game(&game, map_matrix);
	mlx_loop(game.mlx_ptr);
	ft_free_split(map_matrix);
}
