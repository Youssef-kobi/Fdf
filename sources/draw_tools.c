/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <yel-kobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:36:25 by ytourame          #+#    #+#             */
/*   Updated: 2020/03/06 04:10:27 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_line(int *xy, int *xyf, t_data d, int c)
{
	int		*dxy;
	int		i;
	int		step;
	float	x;
	float	y;

	i = 0;
	dxy = (int*)malloc(2 * sizeof(int));
	dxy[0] = xyf[0] - xy[0];
	dxy[1] = xyf[1] - xy[1];
	step = abs(dxy[0]) > abs(dxy[1]) ? abs(dxy[0]) : abs(dxy[1]);
	x = (float)xy[0];
	y = (float)xy[1];
	c = d.c == 0 ? c : d.c;
	while (i <= step)
	{
		mlx_pixel_put(d.mp, d.wp, ((int)x + d.mr[0]), ((int)y + d.mr[1]), c);
		x = x + ((float)dxy[0] / (float)step);
		y = y + ((float)dxy[1] / (float)step);
		i++;
	}
	free(dxy);
}

void	draw_f(t_data d)
{
	int x;
	int y;

	y = -1;
	while (++y < d.yx && (x = -1))
		while (++x < d.xx)
		{
			if (d.pers == 'p')
				draw_para(x, y, d);
			else if (d.pers == 'i')
				draw_iso(x, y, d);
		}
}

void	draw_iso(int x, int y, t_data d)
{
	int *xy;
	int *xyf;
	int c;

	xy = (int*)malloc(2 * sizeof(int));
	xyf = (int*)malloc(2 * sizeof(int));
	xy[0] = ((x - y) * cos(d.an)) * d.zc;
	xy[1] = ((x + y) * sin(d.an) - d.dt[y][x]) * d.zc;
	if ((x + 1) < d.xx)
	{
		xyf[0] = ((x + 1 - y) * cos(d.an)) * d.zc;
		xyf[1] = ((x + 1 + y) * sin(d.an) - d.dt[y][x + 1]) * d.zc;
		c = d.dt[y][x + 1] > 0 ? 0100100220 : 0255000000;
		draw_line(xy, xyf, d, c);
	}
	if ((y + 1) < d.yx)
	{
		xyf[0] = ((x - y - 1) * cos(d.an)) * d.zc;
		xyf[1] = ((x + y + 1) * sin(d.an) - d.dt[y + 1][x]) * d.zc;
		c = d.dt[y + 1][x] > 0 ? 0100100220 : 0255000000;
		draw_line(xy, xyf, d, c);
	}
	free(xy);
	free(xyf);
}

void	draw_para(int x, int y, t_data d)
{
	int *xy;
	int *xyf;
	int c;

	xy = (int*)malloc(2 * sizeof(int));
	xyf = (int*)malloc(2 * sizeof(int));
	xy[0] = x * d.zc;
	xy[1] = y * d.zc;
	if ((x + 1) < d.xx)
	{
		xyf[0] = (x + 1) * d.zc;
		xyf[1] = y * d.zc;
		c = d.dt[y][x + 1] > 0 ? 0100100220 : 0255000000;
		draw_line(xy, xyf, d, c);
	}
	if ((y + 1) < d.yx)
	{
		xyf[0] = x * d.zc;
		xyf[1] = (y + 1) * d.zc;
		c = d.dt[y + 1][x] > 0 ? 0100100220 : 0255000000;
		draw_line(xy, xyf, d, c);
	}
	free(xy);
	free(xyf);
}
