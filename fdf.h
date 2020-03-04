/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <yel-kobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 23:02:19 by ytourame          #+#    #+#             */
/*   Updated: 2020/03/04 11:01:43 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "get_next_line/libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include "mlx.h"

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	pers;
	int		**data;
	int		*margin;
	int 	xmax;
	int		ymax;
	int		zoom_coef;
	int		color;
	float 	angle;
}				t_data;

void	read_file(char **argv,t_data *struc);
int		count_line(char **argv);
int		count_len(char **argv,t_data *struc);
void	parser(t_data *struc, char **saved,int last_len);
int		*get_margin(t_data struc);
int		get_zoom_coef(t_data struc);
void	draw_line(int *xy,int *xyf , t_data struc, int c);
void	draw_iso(t_data struc);
void	draw_para(t_data struc);
int		key_hook(int key, void *param);
void	draw(t_data struc);
void	free_struc(t_data *struc,int exit);
void	ft_error(char *str);
void	ft_clean(t_data *struc, char **saved,char *buff, int index);


