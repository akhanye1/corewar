/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssekese <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 12:16:27 by ssekese           #+#    #+#             */
/*   Updated: 2017/08/29 07:39:51 by ssekese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int     ft_ld(t_conv **instruct, int total_bytes, t_label *labels)
{
	char    *defix;
	char    **split;
	int     i;

	if (!(defix = ft_strdefix((*instruct)->line, ' ')) ||
			!(split = ft_strsplit(defix, ',')))
		return (0);
	if (!((*instruct)->opcode = ft_get_opcode("ld")))
		return (0);
	(*instruct)->bytes = 2;
	(*instruct)->hasencoding = 1;
	(*instruct)->encoding = ft_get_encoding((*instruct)->line);
	(*instruct)->n_params = 2;
	(*instruct)->index = total_bytes + 1;
	(*instruct)->indir_bytes = T_IND;
	(*instruct)->dir_bytes = T_IND;
	ft_decoding(instruct);
	fill_params(instruct, split, labels);
	i = -1;
	while (++i < (*instruct)->n_params)
		(*instruct)->bytes += (*instruct)->b_param[i];
	ft_freestrsplit(split);
	free(defix);
	return (1);
}
