/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <heolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:13:11 by heolivei          #+#    #+#             */
/*   Updated: 2023/06/28 23:21:55 by heolivei         ###   ########.fr       */
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
        free(*matrix);
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

void    ft_checklayout(char *line, t_err *map_err, t_lay *lay, int is_one_or_last)
{
    if (!lay->n_col)
        lay->n_col = (ft_strlen(line) - 1);
    if (lay->n_col && ((lay->n_col != (int)ft_strlen(line) && !ft_strchr(line, '\n')) || (lay->n_col != (int)ft_strlen(line) - 1 && ft_strchr(line, '\n'))))
        map_err->inv_rowlen = 1;
    if (line[0] != '1' || line[lay->n_col - 1] != '1' || (ft_countchar(line, '1') != lay->n_col && is_one_or_last))
        map_err->inv_borders = 1;
    lay->n_exit += ft_countchar(line, 'E');
    lay->n_person += ft_countchar(line, 'P');
    lay->n_collect += ft_countchar(line, 'C');
    map_err->inv_n_exits = lay->n_exit < 1;
    map_err->inv_n_persons = lay->n_person < 1;
    map_err->inv_n_collect = lay->n_collect < 1;
    while (line && *line)
    {
        if (!ft_strchr("01CEP\n", *line))
            map_err->inv_char = 1;
        line++;
    }
}
void    ft_readlayout(int fd, t_err *map_err, t_lay *lay, char **map_str)
{
    char    *line;
    char    *last_line;

    line = NULL;
    last_line = NULL;
    *map_str = ft_substr("", 0, 0);
    while (1)
    {
        line = get_next_line(fd);
        if(!line)
        {
            if(!lay->n_col)
                ft_error_filter("Map is empty", NULL);
            else
                ft_checklayout(last_line, map_err, lay, 1);
            free(last_line);
            break;
        }
        free(last_line);
        ft_checklayout(line, map_err, lay, !lay->n_row);
        last_line = ft_substr(line, 0, ft_strlen(line));
        *map_str = ft_strjoin_gnl(*map_str, line);
        free(line);
        lay->n_row++;
        ft_printf("%s\n", *map_str);
    }
}

int    ft_check_error(t_err *map_err, char **map_str)
{
    if (map_err->inv_rowlen)
        ft_error_filter("The map is not rectangular!", map_str);
    if (map_err->inv_borders)
        ft_error_filter("Invalid map periphery/borders!", map_str);
    if (map_err->inv_char)
        ft_error_filter("Invalid character in map!", map_str);
    if (map_err->inv_n_exits)
        ft_error_filter("Invalid numbers of exits!", map_str);
    if (map_err->inv_n_persons)
        ft_error_filter("Invalid numbers of players!", map_str);
    if (map_err->inv_n_collect)
        ft_error_filter("Invalid numbers of collectibles!", map_str);
    return (0);
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
    ft_printf("%s", map_str);
    ft_check_error(&map_err, &map_str);
    map_matrix = ft_split(map_str, '\n');
    free(map_str);
    return (map_matrix);
}

int	main(int argc, char **argv)
{
	int fd;
    t_lay   layout;
    char **map_matrix;

    map_matrix = NULL;
	fd = checker_general_params(argc, argv);

    map_matrix = ft_check_map(fd, &layout);
	return (0);
}
