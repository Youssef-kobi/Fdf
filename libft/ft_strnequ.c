/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:44:57 by yel-kobi          #+#    #+#             */
/*   Updated: 2019/04/18 02:17:22 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int cmp;

	if (!s1 || !s2)
		return (0);
	cmp = ft_strncmp(s1, s2, n);
	if (cmp == 0)
		return (1);
	else
		return (0);
}
