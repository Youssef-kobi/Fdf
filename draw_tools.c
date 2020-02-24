/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <yel-kobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:36:25 by ytourame          #+#    #+#             */
/*   Updated: 2020/02/24 23:23:08 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line/libft/libft.h"

// void isometric(float *x,float *y, int z)
// {
// 	x =(x-y) * cos(angle);
// 	y =(x+y) * sin(angle) - z;
	
// }
void draw_line(int *xy,int *xyf ,void *mlx_ptr, void *win_ptr)
{
	int dx;
	int dy;
	int i;
	int step;
	float xinc;
	float yinc;
	float x;
	float y;

	//isometric(float *x,float *y, int z)
	i = 0;
	dx = xyf[0] - xy[0];
	dy = xyf[1] - xy[1];
	step = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	x = (float)xy[0];
	y = (float)xy[1];
	xinc = (float)dx / (float)step;
	yinc = (float)dy/ (float)step;
	while (i <= step)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, (int)x, (int)y, 0255000000);
		x = x + xinc;
		y = y + yinc;
		i++;
	}
}

void	draw_para(int **coord,int lines,int len,void *mlx_ptr,void *win_ptr)
{
	int x;
	int y;
	int *xy;
	int *xyf;

	x = 0;
	y = 0;
	xy = (int*)malloc(2 * sizeof(int));
	xyf = (int*)malloc(2 * sizeof(int));
	while (y < lines)
	{
		while(x < len)
		{
			xy[0] = x * 15;
			xy[1] = y * 15;
			if((x + 1) < len )
			{
				xyf[0] = (x + 1) * 15;
				xyf[1] = y * 15;
				draw_line(xy, xyf, mlx_ptr, win_ptr);
			}
			if((y + 1) < lines)
			{
				xyf[0] = x * 15;
				xyf[1] = (y + 1) * 15;
				draw_line(xy, xyf, mlx_ptr, win_ptr);
			}
			x++;
		}
		x = 0;
		y++;
	}
}
