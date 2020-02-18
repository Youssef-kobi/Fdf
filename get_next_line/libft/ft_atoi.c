/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:27:15 by yel-kobi          #+#    #+#             */
/*   Updated: 2019/04/19 02:10:33 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '\0')
		return (0);
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
			str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = (str[i] == '-' ? -1 : 1);
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		if (result > (result * 10 + (str[i] - '0')))
			return (sign == -1 ? 0 : -1);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}
