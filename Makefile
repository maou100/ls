# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feedme <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/14 15:17:21 by feedme            #+#    #+#              #
#    Updated: 2018/08/14 15:29:02 by feedme           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

FLAGS = -Wall -Wextra -Werror

SRC = 
OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ) includes/ft_ls.h
		make -C libft/
		gcc $(FLAGS) -I libft -c $(SRC)
		gcc -o $(NAME) $(OBJ) -I libft/ -I mlx/ libft/libft.a mlx/libmlx.a  -framework OpenGL -framework AppKit
clean:
	make -C libft/ clean
	rm -rf $(OBJ) *.o

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all
