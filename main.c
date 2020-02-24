/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <yel-kobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 01:13:03 by yel-kobi          #+#    #+#             */
/*   Updated: 2020/02/24 23:28:45 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include "get_next_line/libft/libft.h"

int     count_line(char **argv)
{
    int     len;
    char *buff;
    int fd;

    buff = NULL;
    len = 0;
    fd = open(argv[1],O_RDONLY);
    while (get_next_line(fd, &buff) > 0)
        len++;
    free(buff);
    buff = NULL;
    close(fd);
    return(len);
}
void parser(int **coord, char **saved, int len)
{
    int x;
    
    x = 0;
    while(x < len)
    {
        (*coord)[x]= ft_atoi(saved[x]);
        free(saved[x++]);
    }
}
int count_len(char **argv,int **coord)
{
    int len;
    char *buff;
    int fd;
    char **saved;
    int last_len;
    
    last_len = 0;
    fd = open(argv[1],O_RDONLY);
    while (get_next_line(fd, &buff) > 0)
    {
        saved = ft_strsplit(buff, ' ');
        len=0;
        while(saved[len])
            len++;
        if(len >= last_len)
            if(last_len == 0)
                last_len=len;
        else
            exit ;
        *coord=(int*)malloc(sizeof(int)*last_len);
        parser(coord, saved, last_len);
        coord++;
        free(buff);
   }
   close(fd);
   return (last_len);
}
void read_file(char **argv,void *mlx_ptr, void *win_ptr)
{
    int **coord;
    int lines;
    int len;

    lines = count_line(argv);
    coord = (int **)malloc(sizeof (char *)*(lines));
    len = count_len(argv, coord);
    draw_para(coord,lines,len,mlx_ptr,win_ptr);
    // int y =-1;
    // int x = -1;
    // while(++y < 11)
    // {
    //     x = -1;
    //     while(++x < 19)
    //     if(coord[y][x] > 9)
    //         printf("%d ",coord[y][x]);
    //     else
    //         printf("%d  ",coord[y][x]);
    //     printf("\n");
    // }
}


int main(int argc, char **argv)
{   
    void *mlx_ptr;
    void *win_ptr;

    
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr,500,500,"ptr");
    read_file(argv,mlx_ptr,win_ptr);

    mlx_loop(mlx_ptr);
}