/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_encoding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 10:34:00 by jngoma            #+#    #+#             */
/*   Updated: 2017/08/22 10:34:02 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

unsigned char		ft_get_encoding(char *str)
{
	int				i;
	int				j;
	char			**grid;
	char			ret[9];

	i = -1;
	j = 0;
	ret[8] = '\0';
	while (i < 7)
		ret[++i] = '0';
	i = -1;
	grid = ft_strsplit(ft_strdefix(str, ' '), ',');
	while (++i < 3)
	{
		ret[j] = (grid[i][0] == 'r') ? '0' : '1';
		ret[j + 1] = (grid[i][0] == 'r') ? '1' : 0;
		ret[j + 1] = (grid[i][0] == '%') ? '0' : '1';
		j += 2;
	}
	return (bintodec(ret));
}
