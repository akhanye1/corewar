/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 17:58:01 by amatshiy          #+#    #+#             */
/*   Updated: 2017/08/31 18:48:21 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int		ft_lld(t_conv **instruct, int total_bytes, t_label *labels)
{
	char	*defix;
	char	**split;
	int		i;

	if (!(defix = ft_strdefix((*instruct)->line, ' ')) ||
			!(split = ft_strsplit(defix, ',')))
		return (0);
	if (!((*instruct)->opcode = ft_get_opcode("ft_lld")))
		return (0);
	(*instruct)->bytes = 1;
	(*instruct)->hasencoding = 0;
	(*instruct)->n_params = 2;
	(*instruct)->index = total_bytes + 1;
	(*instruct)->indir_bytes = IND_SIZE;
	(*instruct)->dir_bytes = IND_SIZE;
	ft_decoding(instruct);
	fill_params(instruct, split, labels);
	i = -1;
	while (++i < (*instruct)->n_params)
		(*instruct)->bytes += (*instruct)->b_param[i];
	ft_destroy_2d((void**)split);
	free(defix);
	return (i);
}
