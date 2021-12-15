# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 15:41:45 by vseel             #+#    #+#              #
#    Updated: 2021/12/14 12:09:26 by vseel            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf
SRCS		=	map_parser/ft_atoi.c map_parser/ft_split.c \
			map_parser/get_next_line.c \
			map_parser/get_next_line_utils.c \
			map_parser/ft_map_parser.c \
			list_utils/ft_lstnew.c list_utils/ft_lstadd_back.c \
			list_utils/ft_lstsize.c \
			line_draw.c line_draw_math.c line_draw_utils.c \
			line_draw_colors.c key_events.c menu_and_info.c \
			ft_itoa.c map_processing.c
			
HEAD		=	fdf.h
PARSHEAD	=	map_parser/gnl_split_atoi.h
LISTHEAD	=	list_utils/list_utils.h
OBJS		=	$(patsubst %.c, %.o, $(SRCS))

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
DEBUG		=	-g -Wall -Wextra

ARLIB		=	ar rcs
RM			=	rm -f

MLXPATH		=	minilibx_macos
LIBMLX		=	libmlx.a
APICONNECT	=	-Lminilibx_macos -lmlx -framework OpenGL -framework AppKit

.PHONY:		all clean fclean re bonus

%.o : %.c	$(HEAD) $(PARSHEAD) $(LISTHEAD)
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(HEAD) $(PARSHEAD) $(LISTHEAD) fdf.c
			@cd $(MLXPATH) && $(MAKE)
			$(CC) $(CFLAGS) $(APICONNECT) *.o map_parser/*.o list_utils/*.o $(MLXPATH)/$(LIBMLX) fdf.c -o $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			@cd $(MLXPATH) && $(MAKE) clean

re:			fclean all

bonus:		all