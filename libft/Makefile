# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heolivei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 21:06:30 by heolivei          #+#    #+#              #
#    Updated: 2022/11/30 14:47:24 by heolivei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS			=	ft_atoi.c \
					ft_strlen.c \
					ft_memcpy.c \
					ft_isalpha.c \
					ft_isdigit.c \
					ft_isalnum.c \
					ft_isascii.c \
					ft_memset.c \
					ft_bzero.c \
					ft_memmove.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_isprint.c \
					ft_toupper.c \
					ft_tolower.c \
					ft_strchr.c \
			       	ft_strrchr.c \
					ft_strncmp.c \
					ft_strlcat.c \
					ft_strlcpy.c \
					ft_strnstr.c \
					ft_calloc.c \
					ft_strdup.c \
					ft_substr.c \
					ft_strjoin.c \
					ft_strtrim.c \
					ft_split.c \
					ft_itoa.c \
					ft_strmapi.c \
					ft_putchar_fd.c \
					ft_striteri.c \
					ft_putstr_fd.c \
					ft_putnbr_fd.c \
					ft_putendl_fd.c \
					ft_printf.c \
					ft_print_hex.c \
					ft_print_number.c \
					ft_print_pointer.c \
					ft_print_unsigned.c \
					get_next_line.c \
					get_next_line_utils.c \


SRCS_BONUS 		=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
				ft_lstmap.c
OBJS			= $(SRCS:.c=.o)
BONUS_OBJS		= $(SRCS_BONUS:.c=.o)
CC			= cc
CFLAGS			= -Wall -Wextra -Werror
LIBCR			= ar rc
RM			= rm -f

NAME			= libft.a

all:			$(NAME)

$(NAME):	$(OBJS)
			$(LIBCR) $(NAME) $(OBJS)

bonus:		$(OBJS) $(BONUS_OBJS)
			$(LIBCR) $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
			$(RM) $(OBJS) $(BONUS_OBJS)
fclean:			clean
			$(RM) $(NAME)

re:			fclean all

so:
			$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS) $(SRCS_BONUS)
			gcc -nostartfiles -shared -o libft.so $(OBJS) $(BONUS_OBJS)
