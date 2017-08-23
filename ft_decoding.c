/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decoding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 13:45:45 by jngoma            #+#    #+#             */
/*   Updated: 2017/08/22 13:45:47 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

char 		*ft_decoding(char *str)
{
	int					i;
	int					j;
	char				**grid;
	static char			ret[4];

	i = -1;
	j = -1;
	ret[3] = '\0';
	grid = ft_strsplit(ft_strdefix(str, ' '), ',');
	while (++i < 3)
	{
		if (grid[i][0] == 'r')
			ret[++j] = '1';
		else if (grid[i][0] == '%')
			ret[++j] = '2';
		else
			ret[++j] = '3';
	}
	return (ret);
}
