/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 07:33:30 by jngoma            #+#    #+#             */
/*   Updated: 2017/08/22 08:51:37 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"
#include <stdio.h>

unsigned char			ft_get_encoding(char **grid)
{
	int				i;
	int				j;
	unsigned char	ret[9];

	i = -1;
	j = 0;
	ret[8] = '\0';
	while (i < 7)
		ret[++i] = '0';
	i = -1;
	while (++i < 3)
	{
		ret[j] = (grid[i][0] == 'r') ? '0' : '1';
		ret[j + 1] = (grid[i][0] == 'r') ? '1' : 0;
		ret[j + 1] = (grid[i][0] == '%') ? '0' : '1';
		j += 2;
		printf("grid[%i][0] is %c\n",i,grid[i][0]);
	}
	printf("%s\n", ret);
	return (ret);
}

unsigned char	*ft_or(char *line)
{
	char	*str;
	char 	**grid;


	str = NULL;
	if ((line[0] == 'o' || line[0] == 'O') &&
		(line [1] == 'r' || line[1] == 'R'))
	{
		str = ft_strdefix(line, 3);
		grid = ft_strsplit(str, ',');
		ft_get_encoding(grid);
	}
	return ((unsigned char *)str);
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_or(av[1]);
	}
	return (0);
}
