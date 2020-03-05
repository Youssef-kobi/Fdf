/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 22:32:05 by yel-kobi          #+#    #+#             */
/*   Updated: 2019/04/19 21:56:42 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *alst;
	t_list *tmp;
	t_list *m;

	if (!lst || !f)
		return (NULL);
	alst = (t_list *)malloc(sizeof(*alst));
	if (alst == NULL)
		return (NULL);
	ft_memcpy(alst, f(lst), sizeof(t_list));
	tmp = alst;
	while (lst->next)
	{
		lst = lst->next;
		m = (t_list *)malloc(sizeof(t_list));
		if (m == NULL)
			return (NULL);
		ft_memcpy(m, f(lst), sizeof(t_list));
		tmp->next = m;
		tmp = tmp->next;
	}
	return (alst);
}
