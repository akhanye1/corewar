/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 06:52:11 by amatshiy          #+#    #+#             */
/*   Updated: 2017/08/28 07:33:13 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int		ft_lld(t_conv *instruct, int total_bytes, t_label *labels)
{
	char	*defix;
	char 	**split;
	char	*decode;
	int		i;

	if (!(defix = ft_strdefix(instruct->line, ' ')) ||
			!(split = ft_strsplit(defix, ',')))
		return (0);
	if (!(instruct->opcode = ft_get_opcode("lld")))
		return (0);
	instruct->bytes = 1;
	instruct->hasencoding = 0;
	instruct->n_params = 2;
	instruct->index = total_bytes + 1;
	instruct->indir_bytes = IND_SIZE;
	instruct->dir_bytes = IND_SIZE;
	decode = ft_decoding(instruct->line, instruct->n_params);
	fill_params(instruct, split, decode, labels);
	i = -1;
	while (++i < instruct->n_params)
		instruct->bytes += instruct->b_param[i];
	return (1);
}
