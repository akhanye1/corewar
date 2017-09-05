/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decoding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 13:45:45 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/05 09:28:03 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

void	ft_decoding(t_conv **inst)
{
	int					index;
	int					j;
	char				**split;
	char				*trimmed;

	index = 0;
	j = -1;
	if (!(trimmed = ft_strtrim((*inst)->line)))
		return ;
	while ((*inst)->line[index] && (((*inst)->line[index] != ' ') &&
				((*inst)->line[index] != '\t')))
		index++;
	if (!(split = ft_strsplit(trimmed + index, SEPARATOR_CHAR)))
		return ;
	free(trimmed);
	index = -1;
	while (++index < (*inst)->n_params)
	{
		if (!(trimmed = ft_strtrim(split[index])))
			return ;
		if (trimmed[0] == 'r')
			(*inst)->param_types[++j] = REG_CODE;
		else
			(*inst)->param_types[++j] = (trimmed[0] == DIRECT_CHAR) ? DIR_CODE : IND_CODE;
		free(trimmed);
	}
	ft_destroy_2d((void**)split);
}
