/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getwlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytourame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 12:56:54 by ytourame          #+#    #+#             */
/*   Updated: 2019/04/23 12:57:22 by ytourame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_getwlen(char const *s, size_t i, char c)
{
	size_t len;

	len = 0;
	while ((char)s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}