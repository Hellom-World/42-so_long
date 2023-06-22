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

int     checker_general_params(int argc, char **argv)
{
        int fd;

        if (argc != 2)
        {
                write(1, "Error_args", 10);
                return (0);
        }
        fd = open(argv[1], O_RDONLY);
        if (fd == -1)
        {
                write(1, "Error_fd", 8);
                return (0);
        }
        if (ft_strrncmp(argv[1], ".ber", 4) != 0)
        {
                write(1, "Error_fx", 8);
                return (0);
        }
        return (fd);
}

char **ft_read_map(int fd, char **map)
{
    char    *line;
    char    *tmp;
    char    *string_total;

    string_total = ft_strdup("");

    while(1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        tmp = string_total;
        string_total = ft_strjoin(tmp, line);
        free(line);
        free(tmp);
        if (string_total == NULL)
        {
            free(map);
            return NULL;
        }
    }
    map = ft_split(string_total, '\n');
    free(string_total);
     if (map == NULL)
        return NULL;
    return (map);
}

int ft_error_filter(char *msg, char **matrix)
{
    if (matrix)
        free(matrix);
    ft_printf("Error\n%s\n", msg);
    exit(0);
    return (0);
}

int ft_check_map(char **map_matrix)
{
    int i;
    int j;

    i = 0;
    while(map_matrix[i])
    {
        j = 0;
        ft_printf("%d\n", ft_strlen(map_matrix));
        while ((i == 0 || i == (ft_strlen(*map_matrix) - 1)) && map_matrix[i][j])
        {
            ft_printf("%c", map_matrix[i][j]);
            if (map_matrix[i][j] != '1')
            {
                ft_printf("\n");
                ft_error_filter("Paredes invalidas", map_matrix);
            }
            j++;
        }
        if(map_matrix[i][j] == '\0')
        {
            ft_printf("\n");
            break;
        }
        ft_printf("\n");
        i++;
    }
    return (0);
}

int	main(int argc, char **argv)
{
	int fd;
    char **map_matrix;

    map_matrix = NULL;
	fd = checker_general_params(argc, argv);
    map_matrix = ft_read_map(fd, map_matrix);
    ft_check_map(map_matrix);
    ft_error_filter("erro de sei la", map_matrix);
	return (0);
}
