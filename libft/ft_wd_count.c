/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wd_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:58:38 by yel-kobi          #+#    #+#             */
/*   Updated: 2019/04/16 17:04:28 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wd_count(char *s, char c)
{
	int words;
	int i;
	int flag;

	words = 0;
	i = 0;
	flag = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			flag = 0;
		else
		{
			if (flag == 0)
				words++;
			flag = 1;
		}
		i++;
	}
	return (words);
}
