/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_items_in_grid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 16:04:18 by gtshekel          #+#    #+#             */
/*   Updated: 2017/08/24 14:12:32 by mmayibo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_items_in_grid(void **grid)
{
	int index;

	index = 0;
	while (grid[index])
		index++;
	return (index);
}
