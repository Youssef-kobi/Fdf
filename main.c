/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <yel-kobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 01:13:03 by yel-kobi          #+#    #+#             */
/*   Updated: 2020/03/04 12:07:00 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	 main(int argc, char **argv)
{
	t_data	struc;

	if (argc != 2)
		ft_error("Usage: ./fdf map.fdf");
	read_file(argv, &struc);
	struc.zoom_coef = get_zoom_coef(struc);
	struc.margin = get_margin(struc);
	struc.angle = 0.50;
	struc.color = 0;
	struc.pers = 'i';
	struc.mlx_ptr = mlx_init();
	struc.win_ptr = mlx_new_window(struc.mlx_ptr, 1000, 1000, "frst draft");
	draw(struc);
	mlx_key_hook(struc.win_ptr, &key_hook, &struc);
	mlx_loop(struc.mlx_ptr);
	return(0);
}


	// int c =0;
	// int v=0;
	// while(c < struc.ymax)
	// {
	// 	while(v<struc.xmax)
	// 	{
	// 		printf("Tab[%d][%d] = %d\n",c,v,struc.data[c][v]);
	// 		v++;
	// 	}
	// v=0;
	// c++;
	// }