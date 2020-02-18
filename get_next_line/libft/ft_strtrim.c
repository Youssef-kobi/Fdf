/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:34:57 by yel-kobi          #+#    #+#             */
/*   Updated: 2019/04/12 15:36:06 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	int		start;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	start = i;
	len = len - 1;
	while ((s[len] == ' ' || s[len] == '\n' || s[len] == '\t') && i < len)
		len--;
	str = (char *)malloc(sizeof(*str) * (len - start) + 1);
	if (str == NULL)
		return (NULL);
	str = ft_strsub(s, start, (len - start + 1));
	str[(len - start) + 1] = '\0';
	return (str);
}
