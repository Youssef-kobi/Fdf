/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <yel-kobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 01:13:03 by yel-kobi          #+#    #+#             */
/*   Updated: 2020/03/05 01:37:22 by ytourame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_data	struc;

	if (argc != 2)
		ft_error("Usage: ./fdf map.fdf");
	read_file(argv, &struc);
	struc.zc = get_zoom_coef(struc);
	struc.mr = get_margin(struc);
	struc.an = 0.50;
	struc.c = 0;
	struc.pers = 'p';
	struc.mp = mlx_init();
	struc.wp = mlx_new_window(struc.mp, 1000, 1000, argv[1]);
	draw(struc);
	mlx_key_hook(struc.wp, &key_hook, &struc);
	mlx_loop(struc.mp);
	return (0);
}
