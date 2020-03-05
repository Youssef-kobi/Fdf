/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 00:48:25 by yel-kobi          #+#    #+#             */
/*   Updated: 2019/04/19 00:30:44 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t len_d;
	size_t len_s;

	i = 0;
	len_d = ft_strlen(dest);
	len_s = ft_strlen(src);
	if (len_d > size)
		return (len_s + size);
	while (src[i] != '\0' && len_d + i < size - 1)
	{
		dest[len_d + i] = src[i];
		i++;
	}
	dest[len_d + i] = '\0';
	return (len_s + len_d);
}
