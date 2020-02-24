/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcount.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytourame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 12:57:36 by ytourame          #+#    #+#             */
/*   Updated: 2019/04/23 12:58:08 by ytourame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_wcount(char const *s, char c)
{
	size_t		i;
	size_t		cmp;

	i = 1;
	cmp = 0;
	if ((char)s[0] != c)
		cmp = 1;
	while (s[i])
	{
		if ((char)s[i - 1] == c && (char)s[i] != c)
			cmp++;
		i++;
	}
	return (cmp);
}
