/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:43:38 by heolivei          #+#    #+#             */
/*   Updated: 2023/07/02 15:42:10 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stddef.h>
# include "./mlx/mlx.h"
# include "./mlx/mlx_int.h"
# include "./libft/libft.h"


typedef struct s_game
{
	void	*mlx;
	void	*win;
}				t_game;

/* Struct to store and handle layout properties */
typedef struct s_lay
{
	int	n_row;
	int	n_col;
	int	n_exit;
	int	n_person;
	int	n_collect;
}				t_lay;

/* Struct to handle all possible layout errors */
typedef struct s_err
{
	int	inv_rowlen;
	int	inv_borders;
	int	inv_char;
	int	inv_n_persons;
	int	inv_n_collect;
	int	inv_n_exits;
}				t_err;

void	ft_readlayout(int fd, t_err *map_err, t_lay *lay, char **map_str);

int		ft_error_filter(char *msg, char **matrix);
t_err	ft_new_struct_map_error(void);
int		ft_check_error(t_err *map_err, char **map_str);

void	ft_checklayout(char *line, t_err *map_err, t_lay *lay, int is_last);
int		checker_general_params(int argc, char **argv);
char	**ft_check_map(int fd, t_lay *layout);

t_lay	ft_new_struct_layout(void);
int		ft_strrncmp(const char *s1, const char *s2, size_t n);
int		ft_countchar(char *str, char c);
char	*ft_strjoin_solong(char *s1, char *s2);
void	ft_free_split(char **split);
/*cc -g -fsanitize=address main.c utils.c all_of_check.c all_of_errors.c libft/libft.a */
#endif
