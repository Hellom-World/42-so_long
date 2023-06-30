/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:43:38 by heolivei          #+#    #+#             */
/*   Updated: 2023/06/15 17:54:20 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stddef.h>
# include "./libft/libft.h"

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

/*cc main.c utils.c all_of_check.c all_of_errors.c libft/libft.a */
#endif
