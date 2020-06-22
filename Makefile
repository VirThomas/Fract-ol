# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/11 14:29:04 by thabdoul          #+#    #+#              #
#    Updated: 2017/07/21 14:22:51 by thabdoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME	= fractol
LIB		= libft
SRCS	= burning_ship.c \
		  draw_all.c \
		  ft_mlxlib.c \
		  draw_all2.c \
		  event.c \
		  julia.c \
		  main.c \
		  mandelbrot.c \
		  reset.c \
		  tricorn.c
HEAD	= mlx/libmlx.a libft/libft.a
OBJ		= $(SRCS:.c=.o)
FLAGS	= -Wall -Wextra -Werror
MLX		= cc -framework OpenGL -framework AppKit -o

all: $(NAME)

$(NAME):
	make -C $(LIB)
	make -C mlx
	$(MLX) $(NAME) $(FLAGS) $(SRCS) $(HEAD) -O3

clean:
	make clean -C $(LIB)
	rm -f $(OBJ)

fclean:
	make fclean -C $(LIB)
	make clean -C mlx
	rm -f $(NAME)

re: fclean all
