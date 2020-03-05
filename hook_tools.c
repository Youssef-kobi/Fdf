/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <yel-kobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 05:48:51 by yel-kobi          #+#    #+#             */
/*   Updated: 2020/03/05 01:44:07 by ytourame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int key, void *param)
{
	t_data	*d;

	d = (t_data*)(param);
	mlx_clear_window(d->mp, d->wp);
	if (key == 53)
		free_struc(d, 53);
	d->pers = key == 34 ? 'i' : d->pers;
	d->pers = key == 35 ? 'p' : d->pers;
	d->zc = key == 69 ? d->zc + 1 : d->zc;
	d->zc = key == 78 ? d->zc - 1 : d->zc;
	d->c = key == 15 ? 0255000000 : d->c;
	d->c = key == 5 ? 0000255000 : d->c;
	d->c = key == 11 ? 0000000255 : d->c;
	d->c = key == 82 ? 0 : d->c;
	d->mr[0] = key == 123 ? d->mr[0] - 4 : d->mr[0];
	d->mr[0] = key == 124 ? d->mr[0] + 4 : d->mr[0];
	d->mr[1] = key == 125 ? d->mr[1] + 4 : d->mr[1];
	d->mr[1] = key == 126 ? d->mr[1] - 4 : d->mr[1];
	d->an = key == 116 ? d->an + 0.01 : d->an;
	d->an = key == 121 ? d->an - 0.01 : d->an;
	draw(*d);
	return (0);
}

void	draw(t_data d)
{
	mlx_string_put(d.mp, d.wp, 10, 840, 0255000000, "(i / p) to cha
			nge perspective");
	mlx_string_put(d.mp, d.wp, 10, 860, 0255000000, "(+ / -) to zo
			om in or out");
	mlx_string_put(d.mp, d.wp, 10, 880, 0255000000, "(r / g / b / 0) to ch
			ange colors");
	mlx_string_put(d.mp, d.wp, 10, 900, 0255000000, "(page-up / p
		age-down) to change perspective an");
	mlx_string_put(d.mp, d.wp, 10, 920, 0255000000, "(Arrows) to move pers
			pective point");
	mlx_string_put(d.mp, d.wp, 10, 940, 0255000000, "(ESC) to quit");
	draw_f(d);
}
