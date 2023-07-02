# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heolivei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/02 15:48:23 by heolivei          #+#    #+#              #
#    Updated: 2023/07/02 17:15:33 by heolivei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	all_of_check.c \
					all_of_errors.c \
					main.c \
					utils.c \


OBJS			= $(SRCS:.c=.o)
CC			= cc
CFLAGS			= -Wall -Wextra -Werror
LIBCR			= ar rc
RM			= rm -f

LIBFTC			= make -C libft/
LIBFT			= libft/libft.a
NAME			= so_long.a

all:			$(NAME)

$(NAME):	$(OBJS)
			$(LIBFTC)
			$(LIBCR) $(NAME) $(OBJS) $(LIBFT)
			$(CC) $(CFLAGS) -g -fsanitize=address -o $(NAME) $(OBJS) $(LIBFT)

clean:
			$(RM) $(OBJS)
			make clean -C libft
fclean:			clean
			$(RM) $(NAME)
			make fclean -C libft

re:			fclean all
			make fclean all -C libft

