/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 10:45:51 by gtshekel          #+#    #+#             */
/*   Updated: 2017/08/28 13:49:47 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int		ft_ldi(t_conv **ins, int total_bytes, t_label *labels)
{
	char	**split;
	int		i;

	if (!(split = ft_strsplit(ft_strdefix((*ins)->line, ' '), SEPARATOR_CHAR)))
		return (0);
	if (!((*ins)->opcode = ft_get_opcode("ldi")))
		return (0);
	(*ins)->bytes = 2;
	(*ins)->hasencoding = 1;
	(*ins)->encoding = ft_get_encoding((*ins)->line);
	(*ins)->n_params = 3;
	(*ins)->index = total_bytes + 1;
	(*ins)->indir_bytes = IND_SIZE;
	(*ins)->dir_bytes = IND_SIZE;
	ft_decoding(ins);
	fill_params(ins, split, labels);
	i = -1;
	while (++i < (*ins)->n_params)
		(*ins)->bytes += (*ins)->b_param[i];
	ft_destroy_2d((void**)split)
	return (1);
}