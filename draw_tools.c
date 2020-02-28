/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <yel-kobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:36:25 by ytourame          #+#    #+#             */
/*   Updated: 2020/02/26 17:54:11 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw_line(int *xy,int *xyf , t_data struc, int c)
{
	int dx;
	int dy;
	int i;
	int step;
	float xinc;
	float yinc;
	float x;
	float y;

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
		mlx_pixel_put(struc.mlx_ptr, struc.win_ptr, ((int)x + struc.margin[0]), ((int)y + struc.margin[1]), c);
		x = x + xinc;
		y = y + yinc ;
		i++;
	}
}

void	draw_iso(t_data struc)
{
	int x;
	int y;
	int c;
	int *xy;
	int *xyf;

	x = 0;
	y = 0;
	xy = (int*)malloc(2 * sizeof(int));
	xyf = (int*)malloc(2 * sizeof(int));
	while (y < struc.ymax)
	{
		while(x < struc.xmax)
		{
			xy[0] = ((x - y) * cos(struc.angle)) * struc.zoom_coef;
			xy[1] = ((x + y) * sin(struc.angle) - struc.data[y][x]) * struc.zoom_coef;
			if((x + 1) < struc.xmax )
			{
				xyf[0] = ((x + 1 - y) * cos(struc.angle)) * struc.zoom_coef;
				xyf[1] = ((x + 1 + y) * sin(struc.angle) - struc.data[y][x + 1]) * struc.zoom_coef;
				c = struc.data[y][x+1] > 0 ? 0100100220 : 0255000000 ;
				c = struc.color == 0 ? c : struc.color;
				draw_line(xy, xyf, struc, c);
			}
			if((y + 1) < struc.ymax)
			{
				xyf[0] = ((x - y - 1) * cos(struc.angle)) * struc.zoom_coef;
				xyf[1] = ((x + y + 1) * sin(struc.angle) - struc.data[y + 1][x]) * struc.zoom_coef;
				c = struc.data[y + 1][x] > 0 ? 0100100220 : 0255000000 ;
				c = struc.color == 0 ? c : struc.color ;
				draw_line(xy, xyf, struc, c);
			}
			x++;
		}
		x = 0;
		y++;
	}
}


void	draw_para(t_data struc)
{
	int x;
	int y;
	int *xy;
	int *xyf;
	int c;

	x = 0;
	y = 0;
	c = 0;
	xy = (int*)malloc(2 * sizeof(int));
	xyf = (int*)malloc(2 * sizeof(int));
	while (y < struc.ymax)
	{
		while(x < struc.xmax)
		{
			xy[0] = x * struc.zoom_coef;
			xy[1] = y * struc.zoom_coef;
			if((x + 1) < struc.xmax )
			{
				xyf[0] = (x + 1) * struc.zoom_coef;
				xyf[1] = y * struc.zoom_coef;
				c = struc.data[y][x + 1] > 0 ? 0100100220 : 0255000000 ;
				c = struc.color == 0 ? c : struc.color;
				draw_line(xy, xyf, struc, c);
			}
			if((y + 1) < struc.ymax)
			{
				xyf[0] = x * struc.zoom_coef;
				xyf[1] = (y + 1) * struc.zoom_coef;
				c = struc.data[y + 1][x] > 0 ? 0100100220 : 0255000000 ;
				c = struc.color == 0 ? c : struc.color;
				draw_line(xy, xyf, struc, c);
			}
			x++;
		}
		x = 0;
		y++;
	}
}
