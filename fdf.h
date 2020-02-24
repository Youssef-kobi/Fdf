/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <yel-kobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 02:46:49 by yel-kobi          #+#    #+#             */
/*   Updated: 2020/02/24 02:04:46 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line/get_next_line.h"
#include "mlx.h"

void	draw_para(int **coord,int lines,int len,void *mlx_ptr,void *win_ptr);
void	draw_line(int *xy,int *xyf ,void *mlx_ptr, void *win_ptr);