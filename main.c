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


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


static void	init(void)
{
	//void	*mlx;
	//void	*mlx_win;
	t_data	img;
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Rookgard");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 6, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 7, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 8, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 9, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 10, 0x00FF0000);
	my_mlx_pixel_put(&img, 6, 5, 0x00FF0000);
	my_mlx_pixel_put(&img, 6, 6, 0x00FF0000);
	my_mlx_pixel_put(&img, 6, 7, 0x00FF0000);
	my_mlx_pixel_put(&img, 6, 8, 0x00FF0000);
	my_mlx_pixel_put(&img, 6, 9, 0x00FF0000);
	my_mlx_pixel_put(&img, 6, 10, 0x00FF0000);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	//mlx_hook(vars.win, 17, 1L << 2, close_window, &vars);
	mlx_loop(vars.mlx);
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
	init();
	free(map_matrix[i]);
	free(map_matrix);
	return (0);
}
