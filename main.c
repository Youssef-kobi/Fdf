/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <yel-kobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 01:13:03 by yel-kobi          #+#    #+#             */
/*   Updated: 2020/02/27 06:12:48 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	 main(int argc, char **argv)
{
	t_data	struc;
	read_file(argv, &struc);
	struc.zoom_coef = get_zoom_coef(struc);
	struc.margin = get_margin(struc);
	struc.angle = 0.50;
	struc.color = 0;
	struc.pers = 'p';
	struc.mlx_ptr = mlx_init();
	struc.win_ptr = mlx_new_window(struc.mlx_ptr, 1000, 1000, "frst draft");
	draw(struc);
	mlx_key_hook(struc.win_ptr, &key_hook, &struc);
	mlx_loop(struc.mlx_ptr);
	// int c =0;
	// while(c < struc.ymax)
	// {
	// free (struc.data[c]);
	// }
	// printf("dd");
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