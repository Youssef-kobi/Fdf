/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 01:35:26 by yel-kobi          #+#    #+#             */
/*   Updated: 2020/03/05 01:23:32 by ytourame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_struc(t_data *struc, int code)
{
	int y;

	y = 0;
	if (struc->mr != NULL)
		free(struc->mr);
	if (struc->dt)
	{
		while (y < struc->yx)
			free(struc->dt[y++]);
		struc->dt = NULL;
	}
	if (code == 53)
		exit(1);
}

void	ft_clean(t_data *struc, char **saved, char *buff, int index)
{
	int y;

	y = 0;
	while (saved[y])
		free(saved[y++]);
	free(saved);
	free(buff);
	while (index)
		free(struc->dt[--index]);
	free(struc->dt);
	ft_error("Error : Invalid File .|.");
}

void	ft_error(char *str)
{
	ft_putendl(str);
	exit(1);
}
