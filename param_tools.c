/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <yel-kobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 05:42:21 by yel-kobi          #+#    #+#             */
/*   Updated: 2020/03/05 01:19:27 by ytourame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*get_margin(t_data struc)
{
	int *xy;

	xy = (int*)malloc(2 * sizeof(int));
	xy[0] = 500 - ((struc.xx / 2) * struc.zc);
	xy[1] = 500 - ((struc.yx / 2) * struc.zc);
	return (xy);
}

int		get_zoom_coef(t_data struc)
{
	int i;

	i = struc.yx > struc.xx ? (1000 / struc.yx) : (1000 / struc.xx);
	i = i > 20 ? 22 : i;
	i = i < 4 ? 4 : i;
	return (i - 2);
}
