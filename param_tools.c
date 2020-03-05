/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 05:42:21 by yel-kobi          #+#    #+#             */
/*   Updated: 2020/03/05 01:04:20 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*get_margin(t_data struc)
{
	int *xy;

	xy = (int*)malloc(2 * sizeof(int));
	xy[0] = 500 - ((struc.xmax / 2) * struc.zoom_coef);
	xy[1] = 500 - ((struc.ymax / 2) * struc.zoom_coef);
	return (xy);
}

int		get_zoom_coef(t_data struc)
{
	int i;

	i = struc.ymax > struc.xmax ? (1000 / struc.ymax) : (1000 / struc.xmax);
	i = i > 20 ? 22 : i;
	i = i < 4 ? 4 : i;
	return (i - 2);
}
