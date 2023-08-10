# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heolivei <heolivei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/02 15:48:23 by heolivei          #+#    #+#              #
#    Updated: 2023/07/19 18:42:50 by heolivei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	all_of_check.c \
					all_of_errors.c \
					game_init.c \
					game_utils.c \
					flood_fill.c \
					main.c \
					utils.c \

OBJS			= $(SRCS:.c=.o)
CC			= cc
CFLAGS			= -Wall -Wextra -Werror -fsanitize=address
LIBCR			= ar rc
RM			= rm -f

MLXFLAGS = -L ./mlx -lmlx -Ilmlx -lXext -lX11
LIBFTC			= make -C libft/
LIBFT			= libft/libft.a
NAME			= so_long

all:			$(NAME)

$(NAME):	$(OBJS)
			$(LIBFTC)
			$(LIBCR) $(NAME) $(OBJS) $(LIBFT)
			$(MAKE) --no-print-directory -C mlx
			$(CC) $(OBJS) $(CFLAGS) $(LIBFT) $(MLXFLAGS) -o $(NAME)

clean:
			$(RM) $(OBJS)
			make clean -C libft
			make clean -C mlx
fclean:			clean
			$(RM) $(NAME)
			make fclean -C libft
			make clean -C mlx

re:			fclean all
			make fclean all -C libft

.SILENT: