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
	return (0);
}

int	cg_map(t_game *game, int i, char c, int ok)
{
	if (ok)
	{
		game->map_matrix[game->p_position.y][game->p_position.x] = '0';
		if (c == 'y')
			game->p_position.y = game->p_position.y + i;
		else
			game->p_position.x = game->p_position.x + i;
		game->map_matrix[game->p_position.y][game->p_position.x] = 'Q';
		return (1);
	}
	else
	{
		if (game->map_matrix[game->p_position.y][game->p_position.x] == 'Q')
			game->map_matrix[game->p_position.y][game->p_position.x] = 'E';
		else
			game->map_matrix[game->p_position.y][game->p_position.x] = '0';

		if (c == 'y')
			game->p_position.y = game->p_position.y + i;
		else
			game->p_position.x = game->p_position.x + i;
		game->map_matrix[game->p_position.y][game->p_position.x] = 'P';
		return (1);
	}
	return (0);
}

int	ft_cond(t_game *game, int i, char c)
{
	char floor;
	if(c == 'y')
	{
		floor = game->map_matrix[game->p_position.y + i][game->p_position.x];
		if (floor != '1')
		{
			if (floor == 'C')
				game->n_colected++;
			else if (floor == 'E' || floor == 'Z')
				return (2);
			return(1);
		}
	}
	else if(c == 'x')
	{
		floor = game->map_matrix[game->p_position.y][game->p_position.x + i];
		if (floor != '1')
		{
			if (floor == 'C')
				game->n_colected++;
			else if (floor == 'E' || floor == 'Z')
				return (2);
			return(1);
		}
	}
	return(0);
}
int	on_keypress(int keysym, t_game *game)
{
	static int	count;

	if((keysym == 'w' || keysym == 65362) && ft_cond(game, -1, 'y') == 1)
		count += cg_map(game, -1, 'y', 0);
	else if((keysym == 'a' || keysym == 65361) && ft_cond(game, -1, 'x') == 1)
		count += cg_map(game, -1, 'x', 0);
	else if((keysym == 's' || keysym == 65364) && ft_cond(game, 1, 'y') == 1)
		count += cg_map(game, 1, 'y', 0);
	else if((keysym == 'd' || keysym == 65363) && ft_cond(game, 1, 'x') == 1)
		count += cg_map(game, 1, 'x', 0);
	else if((keysym == 'w' || keysym == 65362) && ft_cond(game, -1, 'y') == 2)
		count += cg_map(game, -1, 'y', 1);
	else if((keysym == 'a' || keysym == 65361) && ft_cond(game, -1, 'x') == 2)
		count += cg_map(game, -1, 'x', 1);
	else if((keysym == 's' || keysym == 65364) && ft_cond(game, 1, 'y') == 2)
		count += cg_map(game, 1, 'y', 1);
	else if((keysym == 'd' || keysym == 65363) && ft_cond(game, 1, 'x') == 2)
		count += cg_map(game, 1, 'x', 1);
	if (game->n_colected == game->layout->n_collect)
		game->map_matrix[game->e_position.y][game->e_position.x] = 'Z';
	if (game->n_colected == game->layout->n_collect && (ft_cond(game, 0, 'y') == 2 || ft_cond(game, 0, 'x') == 2 ))
	{
		ft_printf("End Game\n");
		return (on_destroy(game));
	}
	ft_printf("%d\n", game->layout->n_collect);
	ft_printf("Moves: %d\n", count);
	ft_printf("colected: %d\n", game->n_colected);
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
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->texture[0], y * 42, x * 42);
			if (game->map_matrix[x][y] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->texture[1], y * 42, x * 42);
			else if (game->map_matrix[x][y] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->texture[2], y * 42, x * 42);
			else if (game->map_matrix[x][y] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->texture[3], y * 42, x * 42);
			else if (game->map_matrix[x][y] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->texture[4], y * 42, x * 42);
			else if (game->map_matrix[x][y] == 'Q')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->texture[5], y * 42, x * 42);
			else if (game->map_matrix[x][y] == 'Z')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->texture[6], y * 42, x * 42);
		}
	}
	return(0);
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
	game.p_position = ft_position(game.map_matrix, 'P');
	game.e_position = ft_position(game.map_matrix, 'E');
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

// loop_hook
// struct root
// reestruturar
