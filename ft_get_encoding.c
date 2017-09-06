/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_encoding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 10:34:00 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/06 10:06:23 by mmayibo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

unsigned char		ft_get_encoding(char *str)
{
	int				i;
	int				j;
	char			**grid;
	static char		ret[9];
	char 			*defix;

	i = -1;
	j = 0;
	ret[8] = '\0';
	while (i < 7)
		ret[++i] = '0';
	i = -1;
	defix = ft_strdefix(str, ' ');
	grid = ft_strsplit(defix, SEPARATOR_CHAR);
	while (grid[++i])
	{
		ret[j] = (grid[i][0] == 'r') ? '0' : '1';
		ret[j + 1] = (grid[i][0] == 'r') ? '1' : 0;
		ret[j + 1] = (grid[i][0] == DIRECT_CHAR) ? '0' : '1';
		j += 2;
	}
	ft_destroy_2d((void**)grid);
	free(defix);
	return (bintodec(ret));
}
