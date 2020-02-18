/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:58:36 by yel-kobi          #+#    #+#             */
/*   Updated: 2019/04/12 15:33:44 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(*str) * len + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0' && i < len)
		str[i++] = (unsigned char)s[start++];
	str[i] = '\0';
	return (str);
}
