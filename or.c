/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 07:33:30 by jngoma            #+#    #+#             */
/*   Updated: 2017/08/21 08:05:12 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

void  ft_or(*t_conv)
{
	int					i;
	unsingned char		*temp;

	i = 1;
	if ((t_conv->line[0] != 'o' || t_conv->line[0] != 'O')
			&& t_conv->line[1] != 'r')
			return ;
	while (t_conv->line[++i] != '\0')
	{
		ft_strsplit(line, ',');
	}
}
