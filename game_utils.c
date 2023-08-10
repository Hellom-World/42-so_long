/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:48:54 by heolivei          #+#    #+#             */
/*   Updated: 2023/08/10 17:49:02 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	press_esc(int keysym, t_game *game)
{
	if (keysym == 65307)
		on_destroy(game);
	return (0);
}

void	put_img(t_game *game, int x, int y, int i)
{
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr, game->texture[i], y * 42, x * 42);
}

int	cg_map(t_game *game, int i, char c, int ok)
{
	if (ok)
	{
		game->map_matrix[game->p_pos.y][game->p_pos.x] = '0';
		if (c == 'y')
			game->p_pos.y = game->p_pos.y + i;
		else
			game->p_pos.x = game->p_pos.x + i;
		game->map_matrix[game->p_pos.y][game->p_pos.x] = 'Q';
		return (1);
	}
	else
	{
		if (game->map_matrix[game->p_pos.y][game->p_pos.x] == 'Q')
			game->map_matrix[game->p_pos.y][game->p_pos.x] = 'E';
		else
			game->map_matrix[game->p_pos.y][game->p_pos.x] = '0';
		if (c == 'y')
			game->p_pos.y = game->p_pos.y + i;
		else
			game->p_pos.x = game->p_pos.x + i;
		game->map_matrix[game->p_pos.y][game->p_pos.x] = 'P';
		return (1);
	}
	return (0);
}

int	ft_cond(t_game *game, int i, char c)
{
	char	floor1;
	char	floor2;

	floor1 = game->map_matrix[game->p_pos.y + i][game->p_pos.x];
	floor2 = game->map_matrix[game->p_pos.y][game->p_pos.x + i];
	if (c == 'y' && floor1 != '1')
	{
		if (floor1 == 'C')
			game->n_colected++;
		else if (floor1 == 'E' || floor1 == 'Z')
			return (2);
		return (1);
	}
	else if (c == 'x' && floor2 != '1')
	{
		if (floor2 == 'C')
			game->n_colected++;
		else if (floor2 == 'E' || floor2 == 'Z')
			return (2);
		return (1);
	}
	return (0);
}
