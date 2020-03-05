/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:28:30 by yel-kobi          #+#    #+#             */
/*   Updated: 2019/04/12 15:05:11 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	unsigned int		len;
	char				*tab;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	tab = (char*)malloc(sizeof(*tab) * len + 1);
	if (tab == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		tab[i] = f(i, ((unsigned char*)s)[i]);
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
