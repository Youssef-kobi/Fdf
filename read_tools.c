/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <yel-kobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 05:36:01 by yel-kobi          #+#    #+#             */
/*   Updated: 2020/02/27 06:03:02 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     count_line(char **argv)
{
    int     len;
    char *buff;
    int fd;

    buff = NULL;
    len = 0;
    fd = open(argv[1],O_RDONLY);
    while (get_next_line(fd, &buff) > 0)
    {
        len++;
        free(buff);
        buff = NULL;
    }
    close(fd);
    return(len);
}
void parser(t_data *struc, char **saved, int len)
{
    int x;
	static int s;
	
    x = 0;
    while(x < len)
    {
        struc->data[s][x]= ft_atoi(saved[x]);
        free(saved[x++]);
    }
	s++;
}
int count_len(char **argv,t_data *struc)
{
    int len;
    char *buff;
    int fd;
    char **saved;
    int last_len;
	int x;

	x=0;
    last_len = 0;
    fd = open(argv[1],O_RDONLY);
    while (get_next_line(fd, &buff) > 0)
    {
        saved = ft_strsplit(buff, ' ');
        len=0;
        while(saved[len] != NULL)
            len++;
        if(len >= last_len)
        {
            if(last_len == 0)
                last_len=len;
        }
        else
            exit ;
        (struc->data[x]) = (int*)malloc(sizeof(int)*last_len);
        parser(struc, saved, last_len);
		x++;
        free(buff);
        buff = NULL;
   }
    free(buff);
    buff = NULL;
   close(fd);
   return (last_len);
}
void read_file(char **argv,t_data *struc)
{
    struc->ymax = count_line(argv);

    (struc->data) = (int **)malloc(sizeof (char *)*(struc->ymax));
    struc->xmax = count_len(argv, struc);
	// int c =0;
	// int v=0;
	// while(c <= struc->ymax)
	// {
	// 	while(v<=struc->xmax)
	// 		printf("  %d",struc->data[c][v++]);
	// 		printf(" \n");
	// v=0;
	// c++;
	//}
	
}