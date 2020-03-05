# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytourame <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/03 21:28:00 by ytourame          #+#    #+#              #
#    Updated: 2020/03/05 01:31:28 by ytourame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB=libft.a

LIB_DIR=libft/

MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a

MINILIBX_DIRECTORY = ./minilibx_macos/

MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)

NAME=fdf

UNITS= draw_tools hook_tools read_tools param_tools main get_next_line exit_tools

SRC=$(addsuffix .c, $(UNITS))

OBJ=$(addsuffix .o, $(UNITS))

CC=cc

CC_FLAGS=-Wall -Werror -Wextra -I.

all: lib $(NAME)

lib:
		make -C $(LIB_DIR) libft.a

$(NAME): lib
		$(CC) $(CC_FLAGS) -c $(SRC)
		$(CC) $(CC_FLAGS) $(OBJ) -L$(LIB_DIR) -lft -o $(NAME) -framework OpenGL -framework AppKit -lmlx

clean:
		/bin/rm -f $(OBJ)
		make -C $(LIB_DIR) clean

fclean: clean
		/bin/rm -f $(NAME)
		make -C $(LIB_DIR) fclean

re: fclean all

%.o : %.c
		@$(CC) -Wall -Wextra -Werror -c $< -o $@%
