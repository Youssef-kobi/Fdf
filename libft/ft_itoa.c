/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:04:16 by yel-kobi          #+#    #+#             */
/*   Updated: 2019/04/16 16:49:44 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*tab;
	int		len;
	size_t	i;
	int		m;

	m = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_len_tab_int(n);
	if (n < 0)
	{
		n *= -1;
		m = 1;
	}
	i = n;
	if (!(tab = ft_strnew(len)))
		return (NULL);
	(n == 0 ? tab[0] = '0' : n * 1);
	while (len > 0)
	{
		tab[--len] = (i % 10 + '0');
		i = i / 10;
	}
	(m == 1 ? tab[0] = '-' : m * 1);
	return (tab);
}
