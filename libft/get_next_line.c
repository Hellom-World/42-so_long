/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <heolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:37:23 by heolivei          #+#    #+#             */
/*   Updated: 2023/01/12 15:54:55 by heolivei         ###   ########.fr       */
/*   Updated: 2023/01/08 21:33:56 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_brute_line(int fd, char *brute_line)
{
	char	*vleitura;
	int		nbl;

	vleitura = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!vleitura)
		return (0);
	nbl = 1;
	while (!ft_strchr_gnl(brute_line, '\n') && nbl != 0)
	{
		nbl = read(fd, vleitura, BUFFER_SIZE);
		if (nbl == -1)
		{
			free(vleitura);
			free(brute_line);
			return (0);
		}
		vleitura[nbl] = '\0';
		brute_line = ft_strjoin_gnl(brute_line, vleitura);
	}
	free(vleitura);
	return (brute_line);
}

char	*ft_liquid_line(char *brute_line)
{
	int		i;
	char	*str;

	i = 0;
	if (!brute_line[i])
		return (0);
	while (brute_line[i] && brute_line[i] != '\n')
		i++;
	while (brute_line[i] && brute_line[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (0);
	i = 0;
	while (brute_line[i] && brute_line[i] != '\n')
	{
		str[i] = brute_line[i];
		i++;
	}
	if (brute_line[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*ft_rest_line(char *brute_line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (!brute_line)
		return (0);
	while (brute_line[i] && brute_line[i] != '\n')
		i++;
	if (!brute_line[i] || brute_line[i + 1] == '\0')
	{
		free(brute_line);
		return (0);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen_gnl(brute_line) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (brute_line[i])
		str[j++] = brute_line[i++];
	str[j] = '\0';
	free(brute_line);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*liquid_line;
	static char	*brute_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	brute_line = ft_brute_line(fd, brute_line);
	if (!brute_line)
		return (0);
	liquid_line = ft_liquid_line(brute_line);
	brute_line = ft_rest_line(brute_line);
	return (liquid_line);
}
/*int     main(void)
{       char    *str;

        int fd = open("test.txt", O_RDONLY);
        str = get_next_line(fd);
        printf("%s", str);
        free(str);
        str = get_next_line(fd);
        printf("%s", str);
        free(str);
        str = get_next_line(fd);
        printf("%s", str);
        free(str);
        str = get_next_line(fd);
        printf("%s", str);
        free(str);
        return 0;
}*/
