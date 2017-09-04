/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 17:06:59 by jngoma            #+#    #+#             */
/*   Updated: 2017/08/29 09:01:48 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int		ft_or(t_conv **instruct, int total_bytes, t_label *labels)
{
	char	**split;
	int		i;

	if (!(split = ft_strsplit(ft_strdefix((*instruct)->line, ' '), ',')))
		return (0);
	if (split[2][0] != 'r')
		return (0);
	if (!((*instruct)->opcode = ft_get_opcode("or")))
		return (0);
	(*instruct)->bytes = 2;
	(*instruct)->hasencoding = 1;
	(*instruct)->encoding = ft_get_encoding((*instruct)->line);
	(*instruct)->n_params = 3;
	(*instruct)->index = total_bytes + 1;
	(*instruct)->indir_bytes = IND_SIZE;
	(*instruct)->dir_bytes = DIR_SIZE;
	ft_decoding(instruct);
	fill_params(instruct, split, labels);
	i = -1;
	while (++i < (*instruct)->n_params)
		(*instruct)->bytes += (*instruct)->b_param[i];
	ft_destroy_2d((void**)split);
	return (1);
}
