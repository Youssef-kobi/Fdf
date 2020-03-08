/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 14:02:47 by yel-kobi          #+#    #+#             */
/*   Updated: 2020/03/08 00:14:52 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# define FD_NUM 4864

# include "../libft/libft.h"
# include <fcntl.h>

int	get_next_line(const int fd, char **line);

#endif
