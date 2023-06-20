/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:13:11 by heolivei          #+#    #+#             */
/*   Updated: 2023/06/19 20:18:59 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stddef.h>
#include "so_long.h"

int ft_strrncmp(const char *s1, const char *s2, size_t n) {
    size_t len1 = 0;
    size_t len2 = 0;

    // Obter o comprimento das strings s1 e s2
    while (s1[len1] != '\0')
        len1++;
    while (s2[len2] != '\0')
        len2++;

    // Ajustar os ponteiros para apontar para o último caractere de cada string
    const char* end1 = s1 + len1 - 1;
    const char* end2 = s2 + len2 - 1;

    // Realizar a comparação de trás para frente
    while (n > 0 && end1 >= s1 && end2 >= s2) {
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
        ft_printf("%d", fd);
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


int	main(int argc, char **argv)
{
	int fd;
    char **map;

    map = NULL;
	fd = checker_general_params(argc, argv);

    map = ft_read_map(fd, map);

    ft_printf("%s", map);

	ft_printf("-%d-", fd);
	return (0);
}
