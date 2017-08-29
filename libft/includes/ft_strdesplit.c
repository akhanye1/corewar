/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdesplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 18:54:13 by jngoma            #+#    #+#             */
/*   Updated: 2017/08/22 07:23:06 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_populate(char **grid, char *str, int c)
{
	int		row;
	int		col;
	int		i;

	row = -1;
	i = 0;
	while (grid[++row])
	{
		col = -1;
		while (grid[row][++col] != '\0')
			str[i++] = grid[row][col];
		str[i++] = c;
	}
	str[--i] = '\0';
	return (str);
}

char	*ft_strdesplit(char **grid, int c)
{
	int		row;
	int		col;
	int		i;

	row = -1;
	i = 1;
	while (grid[++row])
	{
		col = -1;
		while (grid[row][++col] != '\0')
			i++;
	}
	i += (row - 1);
	return ((ft_populate(grid, ft_strnew((unsigned int)i - 1), c)));
}
