/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 01:13:03 by yel-kobi          #+#    #+#             */
/*   Updated: 2020/02/16 01:13:05 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
/* int main()
{
    void *mlx_ptr;
    void *win_ptr;
    int x = 0;
    int y = 0;
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr,1000,1000,"New Window");
    //while (x++ < 1000 && y++ < 1000)
    //{
        //mlx_pixel_put(mlx_ptr,win_ptr,x,y,255);
        //mlx_string_put (mlx_ptr,win_ptr,200,500,255,"Zebi" );
    //}
    mlx_string_put (mlx_ptr,win_ptr,500 ,500,255,"ZEBI" );
    mlx_loop(mlx_ptr);
}*/

int main(int argc, char **argv)
{
int fd = 0;
char *tab;
int line =0;
char **saved;
fd = open(argv[1],O_RDONLY);
printf("fd id is = %d \n",fd); 
while (get_next_line(fd,&tab) > 0)
{
    printf("Line = %s\n",tab);
    saved[line++] = tab;
}
}