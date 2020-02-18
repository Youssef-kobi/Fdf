/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 14:02:34 by yel-kobi          #+#    #+#             */
/*   Updated: 2019/06/23 21:59:02 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		protect(char **rest)
{
	free(rest);
	return (-1);
}

static int		addtoline(char **rest, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*rest)[len] != '\n' && (*rest)[len] != '\0')
		len++;
	if ((*rest)[len] == '\n')
	{
		if ((*line = ft_strsub(*rest, 0, len)) == NULL)
			protect(rest);
		if ((tmp = ft_strdup(&((*rest)[len + 1]))) == NULL)
			protect(rest);
		free(*rest);
		*rest = tmp;
		if (*rest[0] == '\0')
			ft_strdel(rest);
	}
	else
	{
		if ((*line = ft_strdup(*rest)) == NULL)
			protect(rest);
		ft_strdel(rest);
	}
	return (1);
}

static int		checker(int fd, char **rest, char **line, int res)
{
	if (res < 0)
		return (-1);
	else if (res == 0 && rest[fd] == NULL)
		return (0);
	else
		return (addtoline(&rest[fd], line));
}

static void		ft_join(int fd, char **rest, char *buff)
{
	char *tmp;

	if ((tmp = ft_strjoin(rest[fd], buff)) == NULL)
		protect(&rest[fd]);
	free(rest[fd]);
	rest[fd] = tmp;
}

int				get_next_line(const int fd, char **line)
{
	int			res;
	char		buff[BUFF_SIZE + 1];
	static char	*rest[FD_NUM];

	res = 0;
	if (fd < 0 || line == NULL || BUFF_SIZE < 1 || FD_NUM < 0)
		return (-1);
	while ((res = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[res] = '\0';
		if (rest[fd] == NULL)
		{
			if ((rest[fd] = ft_strdup(buff)) == NULL)
				return (-1);
		}
		else
			ft_join(fd, rest, buff);
		if (ft_strchr(rest[fd], '\n'))
			break ;
	}
	return (checker(fd, rest, line, res));
}
