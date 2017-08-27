/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decoding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 13:45:45 by jngoma            #+#    #+#             */
/*   Updated: 2017/08/27 07:34:23 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

char 		*ft_decoding(char *str, int n_params)
{
	int					i;
	int					j;
	char				**grid;
	static char			ret[4];


	i = -1;
	j = -1;
	ft_bzero(ret, 4);
	grid = ft_strsplit(ft_strdefix(str, ' '), ',');
	while (++i < n_params)
	{
		if (grid[i][0] == 'r')
			ret[++j] = REG_CODE;
		else if (grid[i][0] == DIRECT_CHAR)
			ret[++j] = DIR_CODE;
		else
			ret[++j] = IND_CODE;
	}
	return (ret);
}
