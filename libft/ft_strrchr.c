/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:12:37 by yel-kobi          #+#    #+#             */
/*   Updated: 2019/04/05 01:34:08 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int len;

	len = ft_strlen(str);
	while (len >= 0 && str[len] != c)
		len--;
	if (str[len] == c)
		return ((char *)str + len);
	return (NULL);
}
