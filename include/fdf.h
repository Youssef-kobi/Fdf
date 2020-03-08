/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <yel-kobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 23:02:19 by ytourame          #+#    #+#             */
/*   Updated: 2020/03/08 00:13:08 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "get_next_line.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>

typedef struct	s_data
{
	void	*mp; //mlx_ptr
	void	*wp; //win_ptr
	char	pers;
	int		**dt; //data
	int		*mr; // margin
	int 	xx; //xmax
	int		yx; //ymax
	int		zc; // zoom_coef
	int		c; //color
	float 	an; //angle
	int		fd;
}				t_data;

void	read_file(char **argv,t_data *struc);
int		count_line(char **argv);
int		count_len(char **argv,t_data *struc);
void	parser(t_data *struc, char **saved, int len);
int		*get_margin(t_data struc);
int		get_zoom_coef(t_data struc);
void	draw_line(int *xy,int *xyf, t_data struc, int c);
void	draw_f(t_data d);
void	draw_para(int x, int y, t_data d);
int		key_hook(int key, void *param);
void	draw(t_data struc);
void	free_struc(t_data *d,int ext);
void    draw_iso(int x, int y, t_data d);
void	ft_error(char *str);
void	ft_clean(t_data *struc, char **saved,char *buff, int index);
