/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <heolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:31:34 by heolivei          #+#    #+#             */
/*   Updated: 2023/08/09 20:57:53 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_game *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (1);
}

int	on_keypress(int keysym, t_game *game)
{
	static int	count;

	if ((keysym == 'w' || keysym == 65362) && ft_cond(game, -1, 'y') == 1)
		count += cg_map(game, -1, 'y', 0);
	else if ((keysym == 'a' || keysym == 65361) && ft_cond(game, -1, 'x') == 1)
		count += cg_map(game, -1, 'x', 0);
	else if ((keysym == 's' || keysym == 65364) && ft_cond(game, 1, 'y') == 1)
		count += cg_map(game, 1, 'y', 0);
	else if ((keysym == 'd' || keysym == 65363) && ft_cond(game, 1, 'x') == 1)
		count += cg_map(game, 1, 'x', 0);
	else if ((keysym == 'w' || keysym == 65362) && ft_cond(game, -1, 'y') == 2)
		count += cg_map(game, -1, 'y', 1);
	else if ((keysym == 'a' || keysym == 65361) && ft_cond(game, -1, 'x') == 2)
		count += cg_map(game, -1, 'x', 1);
	else if ((keysym == 's' || keysym == 65364) && ft_cond(game, 1, 'y') == 2)
		count += cg_map(game, 1, 'y', 1);
	else if ((keysym == 'd' || keysym == 65363) && ft_cond(game, 1, 'x') == 2)
		count += cg_map(game, 1, 'x', 1);
	ft_printf("Moves: %d\n", count);
	if (game->n_colected == game->layout->n_collect)
		game->map_matrix[game->e_pos.y][game->e_pos.x] = 'Z';
	if (game->n_colected == game->layout->n_collect
		&& (ft_cond(game, 0, 'y') == 2 || ft_cond(game, 0, 'x') == 2))
		return (on_destroy(game));
	return (press_esc(keysym, game));
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
	game->texture[5] = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/door_off_with_player.xpm", &width, &height);
	game->texture[6] = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/door_on.xpm", &width, &height);
}

int	load_game(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	while (game->map_matrix[++x])
	{
		y = -1;
		while (game->map_matrix[x][++y])
		{
			put_img(game, x, y, 0);
			if (game->map_matrix[x][y] == 'P')
				put_img(game, x, y, 1);
			else if (game->map_matrix[x][y] == '1')
				put_img(game, x, y, 2);
			else if (game->map_matrix[x][y] == 'C')
				put_img(game, x, y, 3);
			else if (game->map_matrix[x][y] == 'E')
				put_img(game, x, y, 4);
			else if (game->map_matrix[x][y] == 'Q')
				put_img(game, x, y, 5);
			else if (game->map_matrix[x][y] == 'Z')
				put_img(game, x, y, 6);
		}
	}
	return (0);
}

void	game_init(char **map_matrix, t_lay *layout)
{
	t_game	game;

	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		ft_printf("error init()");
	game.win_ptr = mlx_new_window (game.mlx_ptr, layout->n_col * 42,
			layout->n_row * 42, "Sobradinho");
	if (!game.mlx_ptr)
		ft_printf("error win()");
	game.map_matrix = map_matrix;
	game.layout = layout;
	game.p_pos = ft_position(game.map_matrix, 'P');
	game.e_pos = ft_position(game.map_matrix, 'E');
	game.n_colected = 0;
	mlx_hook(game.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &game);
	mlx_hook(game.win_ptr, DestroyNotify, StructureNotifyMask,
		&on_destroy, &game);
	load_assets(&game);
	load_game(&game);
	mlx_loop_hook(game.mlx_ptr, load_game, &game);
	mlx_loop(game.mlx_ptr);
	ft_free_split(map_matrix);
}
