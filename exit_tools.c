/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <yel-kobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 01:35:26 by yel-kobi          #+#    #+#             */
/*   Updated: 2020/03/04 12:09:59 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void free_struc(t_data *struc,int code)
{
    int x;
    int y;

    y = 0;
    
    if (struc->margin != NULL)
        free(struc->margin);
    if (struc->data)
    {
    while(y < struc->ymax)
        free(struc->data[y++]);
        struc->data=NULL;
    }
    if (code == 53)
        exit(1);
}

void ft_clean(t_data *struc ,char **saved,char *buff,int index)
{
    int y;
    
    y = 0;
    while(saved[y])
        free(saved[y++]);
    free(saved);
    free(buff);
    while(index)
        free(struc->data[--index]);
    free(struc->data);
    ft_error("Error : Invalid File .|.");
}

void ft_error(char *str)
{
    ft_putendl(str);
    exit(1);
}