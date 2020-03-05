/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 01:14:23 by yel-kobi          #+#    #+#             */
/*   Updated: 2020/03/05 01:24:20 by ytourame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_line(char **argv)
{
	int		len;
	char	*buff;
	int		fd;

	len = 0;
	if ((fd = open(argv[1], O_RDONLY)) > 0)
	{
		while (get_next_line(fd, &buff) > 0)
		{
			len++;
			free(buff);
		}
	}
	else
		ft_error("Error : File Not Found");
	close(fd);
	return (len);
}

void	parser(t_data *struc, char **saved, int last_len)
{
	int				x;
	static int		s;

	x = 0;
	(struc->dt[s]) = (int*)malloc(sizeof(int) * last_len);
	while (x < last_len)
	{
		struc->dt[s][x] = ft_atoi(saved[x]);
		free(saved[x++]);
	}
	free(saved);
	s++;
}

int		count_len(char **argv, t_data *struc)
{
	int		len;
	int		index;
	char	*buff;
	char	**saved;
	int		last_len;

	last_len = 0;
	index = -1;
	struc->fd = open(argv[1], O_RDONLY);
	while (get_next_line(struc->fd, &buff) > 0)
	{
		index++;
		saved = ft_strsplit(buff, ' ');
		len = 0;
		while (saved[len] != NULL)
			len++;
		if (len >= last_len)
			last_len == 0 ? last_len = len : 1;
		else
			ft_clean(struc, saved, buff, index);
		parser(struc, saved, last_len);
		free(buff);
	}
	close(struc->fd);
	return (last_len);
}

void	read_file(char **argv, t_data *struc)
{
	struc->yx = count_line(argv);
	(struc->dt) = (int **)malloc(sizeof(int *) * (struc->yx));
	struc->xx = count_len(argv, struc);
}
