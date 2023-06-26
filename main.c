/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:13:11 by heolivei          #+#    #+#             */
/*   Updated: 2023/06/21 18:45:51 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stddef.h>
#include "so_long.h"

int	ft_strrncmp(const char *s1, const char *s2, size_t n)
{
	size_t	len1;
	size_t	len2;
	const char	*end;

	len1 = 0;
	len2 = 0;
	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;
	const char* end1 = s1 + len1 - 1;
	const char* end2 = s2 + len2 - 1;
	while (n > 0 && end1 >= s1 && end2 >= s2)
	{
		if (*end1 != *end2)
			break;
		end1--;
		end2--;
		n--;
	}
	if (n == 0)
		return 0;
	return (unsigned char)(*end1) - (unsigned char)(*end2);
}

int ft_countchar(char *str, char c) {
    int count = 0;

    while (*str != '\0') {
        if (*str == c) {
            count++;
        }
        str++;
    }

    return count;
}

int ft_error_filter(char *msg, char **matrix)
{
    if (matrix)
        free(matrix);
    ft_printf("Error\n%s\n", msg);
    exit(0);
    return (0);
}
int     checker_general_params(int argc, char **argv)
{
        int fd;

        if (argc != 2)
        {
                ft_error_filter("Only 2 Arguments -> ./so_long map.ber", NULL);
                return (0);
        }
        fd = open(argv[1], O_RDONLY);
        if (fd == -1)
        {
                ft_error_filter("Error opening the file .ber", NULL);
                return (0);
        }
        if (ft_strrncmp(argv[1], ".ber", 4) != 0)
        {
                ft_error_filter("The map file needs to be .ber", NULL);
                return (0);
        }
        return (fd);
}
t_lay   ft_new_struct_layout(void)
{
    t_lay   layout;

    layout.n_row = 0;
    layout.n_col = 0;
    layout.n_exit = 0;
	layout.n_person = 0;
	layout.n_collect = 0;

    return (layout);
}

t_err   ft_new_struct_map_error(void)
{
    t_err   error;

    error.inv_rowlen = 0;
	error.inv_borders = 0;
	error.inv_char = 0;
	error.inv_n_persons = 0;
	error.inv_n_collect = 0;
	error.inv_n_exits = 0;
    return (error);
}

void    ft_readlayout(int fd, t_err *map_err, t_lay *lay, char **map_str)
{
    char    *line;
    char    *last_line;
    int     is_last = 0;

    line = NULL;
    last_line = NULL;
    *map_str = ft_substr("", 0, 1);
    while (1)
    {
        line = get_next_line(fd);
        if(!line)
        {
            /*if(!lay->n_col)
                ft_error_filter("Map is empty", NULL);*/
            free(last_line);
            break;
        }
        free(last_line);
        //ft_checklayout(line, map_err, lay, !lay->n_row);
        last_line = ft_substr(line, 0, ft_strlen(line));
        *map_str = ft_strjoin(*map_str, line);
        lay->n_col = ft_strlen(line) - 1;

        if (ft_countchar(line, '1') != lay->n_col && is_last)
        {
            is_last =  1;
        }

        ft_printf("%i\n", is_last);
        lay->n_row++;
    }
}
char    **ft_check_map(int fd, t_lay *layout)
{
    char    *map_str;
    char    **map_matrix;
    t_err   map_err;

    map_str = NULL;
    map_matrix = NULL;
    map_err = ft_new_struct_map_error();
    *layout = ft_new_struct_layout();
    ft_readlayout(fd, &map_err, layout, &map_str);
    return (map_matrix);
}

int	main(int argc, char **argv)
{
	int fd;
    t_lay   layout;
    t_err   map_error;
    char **map_matrix;

    map_matrix = NULL;
	fd = checker_general_params(argc, argv);

    map_matrix = ft_check_map(fd, &layout);
	return (0);
}
