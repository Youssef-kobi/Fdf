/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 12:11:13 by yel-kobi          #+#    #+#             */
/*   Updated: 2019/04/16 16:55:31 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*str;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = 0;
	str = (char *)malloc(sizeof(*str) * (len_s1 + len_s2 + 1));
	if (str == NULL)
		return (NULL);
	ft_bzero(str, (len_s1 + len_s2 + 1));
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str = ft_strcat(str, s2);
	return (str);
}
