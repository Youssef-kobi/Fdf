/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 03:18:21 by yel-kobi          #+#    #+#             */
/*   Updated: 2019/04/19 01:18:31 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (find[j] == '\0')
		return ((char *)str);
	while (str[i] != '\0' && i < n)
	{
		j = 0;
		while (find[j] == str[i + j] && find[j] != '\0' && i + j < n)
		{
			j++;
			if (find[j] == '\0')
				return ((char *)str + i);
		}
		i++;
	}
	return (NULL);
}
