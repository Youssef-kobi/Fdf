/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 10:41:25 by yel-kobi          #+#    #+#             */
/*   Updated: 2019/04/08 11:10:02 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *tab;

	tab = (char *)malloc(sizeof(*tab) * size);
	if (tab == NULL)
		return (NULL);
	ft_bzero(tab, size);
	return (tab);
}
