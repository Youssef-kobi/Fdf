# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-kobi <yel-kobi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/03 21:28:00 by ytourame          #+#    #+#              #
#    Updated: 2020/03/08 00:06:33 by yel-kobi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB=libft.a

LIB_DIR=libft/

NAME=fdf

INCLUDE=include/fdf.h

UNITS=sources/draw_tools sources/hook_tools sources/read_tools sources/param_tools sources/main sources/get_next_line sources/exit_tools 

UNITS_OBJ=draw_tools hook_tools read_tools param_tools main get_next_line exit_tools 

SRC=$(addsuffix .c, $(UNITS))

OBJ=$(addsuffix .o, $(UNITS_OBJ))
CC=cc

CC_FLAGS=-Wall -Werror -Wextra -I.

all: lib $(NAME)

lib:
		@make -C $(LIB_DIR)
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

sources/%.o : sources/%.c
		@$(CC) -Wall -Wextra -Werror -c $< -o $@%