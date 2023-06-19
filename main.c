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
	printf("%d", fd);
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


int	main(int argc, char **argv)
{
	int fd;

	fd = checker_general_params(argc, argv);

	printf("%d", fd);
	return (0);
}
