/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:50:59 by yel-kobi          #+#    #+#             */
/*   Updated: 2019/04/16 17:04:03 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		start;
	int		j;
	int		wd;

	wd = ft_wd_count((char *)s, c);
	i = 0;
	j = 0;
	tab = (char **)malloc(sizeof(char *) * (wd + 1));
	if (tab == NULL)
		return (NULL);
	while (j < wd)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		tab[j++] = ft_strsub((char *)s, start, (i - start));
	}
	tab[j] = NULL;
	return (tab);
}
