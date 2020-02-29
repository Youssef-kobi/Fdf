/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 01:35:26 by yel-kobi          #+#    #+#             */
/*   Updated: 2020/02/29 01:35:27 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void free_struc(t_data *struc,int exit)
{
    int x;
    int y;

    y = 0;
    free(struc->margin);
    struc->margin=NULL;
    while(y < struc->ymax)
        free(struc->data[y++]);
    struc->data=NULL;
    if (exit = 53)
    exit;
}