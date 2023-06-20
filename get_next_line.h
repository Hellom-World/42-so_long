/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <heolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:02:24 by heolivei          #+#    #+#             */
/*   Updated: 2023/01/10 22:09:02 by heolivei         ###   ########.fr       */
/*   Created: 2022/12/08 15:37:47 by heolivei          #+#    #+#             */
/*   Updated: 2023/01/07 13:17:46 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_brute_line(int fd, char *brute_line);
char	*ft_liquid_line(char *brute_line);
char	*ft_rest_line(char *brute_line);

size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);

#endif
