SRC = *.c
RM = /bin/rm -f
HEADER = fdf.h
OPTION = -c
CFLAGS = -Wall -Wextra -Werror

all:
		gcc  main.c  get_next_line/get_next_line.c  get_next_line/libft/libft.a  -lmlx -lXext -lX11 -L /home/yel-kobi/minilibx
cc -I /usr/local/include/ main.c -L /usr/local/lib -lmlx -framework OpenGl -framework Appkit
