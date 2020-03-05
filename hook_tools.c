/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 05:48:51 by yel-kobi          #+#    #+#             */
/*   Updated: 2020/03/05 01:03:17 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int key, void *param)
{
	t_data	*struc;

	struc = (t_data*)(param);
	mlx_clear_window(struc->mlx_ptr, struc->win_ptr);
	if (key == 53)
		free_struc(struc, 53);
	struc->pers = key == 34 ? 'i' : struc->pers;
	struc->pers = key == 35 ? 'p' : struc->pers;
	struc->zoom_coef = key == 69 ? struc->zoom_coef + 1 : struc->zoom_coef;
	struc->zoom_coef = key == 78 ? struc->zoom_coef - 1 : struc->zoom_coef;
	struc->color = key == 15 ? 0255000000 : struc->color;
	struc->color = key == 5 ? 0000255000 : struc->color;
	struc->color = key == 11 ? 0000000255 : struc->color;
	struc->color = key == 82 ? 0 : struc->color;
	struc->margin[0] = key == 123 ? struc->margin[0] - 4 : struc->margin[0];
	struc->margin[0] = key == 124 ? struc->margin[0] + 4 : struc->margin[0];
	struc->margin[1] = key == 125 ? struc->margin[1] + 4 : struc->margin[1];
	struc->margin[1] = key == 126 ? struc->margin[1] - 4 : struc->margin[1];
	struc->angle = key == 116 ? struc->angle + 0.01 : struc->angle;
	struc->angle = key == 121 ? struc->angle - 0.01 : struc->angle;
	draw(*struc);
	return (0);
}

void	draw(t_data struc)
{
	void *m;
	void *w;

	m = struc.mlx_ptr;
	w = struc.win_ptr;
	mlx_string_put(m, w, 10, 840, 0255000000, "(i / p) to change perspective");
	mlx_string_put(m, w, 10, 860, 0255000000, "(+ / -) to zoom in or out");
	mlx_string_put(m, w, 10, 880, 0255000000, "(r / g / b / 0)change colors");
	mlx_string_put(m, w, 10, 900, 0255000000, "(P-up/down)change perspective");
	mlx_string_put(m, w, 10, 920, 0255000000, "(Arrows)move perspective point");
	mlx_string_put(m, w, 10, 940, 0255000000, "(ESC) to quit");
	if (struc.pers == 'i')
		draw_iso(struc);
	else
		draw_para(struc);
}
