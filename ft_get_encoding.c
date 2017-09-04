/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_encoding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 10:34:00 by jngoma            #+#    #+#             */
/*   Updated: 2017/08/24 12:02:52 by mmayibo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

unsigned char		ft_get_encoding(char *str)
{
	int							i;
	int							j;
	char						**grid;
	static char			ret[9];

	i = -1;
	j = 0;
	ret[8] = '\0';
	while (i < 7)
		ret[++i] = '0';
	i = -1;
	grid = ft_strsplit(ft_strdefix(str, ' '), SEPARATOR_CHAR);
	while(grid[++i])
	{
		ret[j] = (grid[i][0] == 'r') ? '0' : '1';
		ret[j + 1] = (grid[i][0] == 'r') ? '1' : 0;
		ret[j + 1] = (grid[i][0] == DIRECT_CHAR) ? '0' : '1';
		j += 2;
	}
	ft_destroy_2d((void**)grid);
	return (bintodec(ret));
}
