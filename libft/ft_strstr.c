/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 02:45:23 by yel-kobi          #+#    #+#             */
/*   Updated: 2019/04/12 14:11:08 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *find)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (find[j] == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == find[j])
		{
			j++;
			if (find[j] == '\0')
				return ((char *)str + i);
		}
		i++;
	}
	return (NULL);
}
