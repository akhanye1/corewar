/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmayibo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 09:32:02 by mmayibo           #+#    #+#             */
/*   Updated: 2017/08/28 16:30:30 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int		ft_live(t_conv **ins, int total_bytes, t_label *labels)
{
	char	**split;
	char	*defix;

	defix = ft_strdefix((*ins)->line, ' ');
	if (!(split = ft_strsplit(defix, SEPARATOR_CHAR)))
		return (0);
	if (!((*ins)->opcode = ft_get_opcode("live")))
		return (0);
	(*ins)->bytes = 5;
	(*ins)->hasencoding = 0;
	(*ins)->n_params = 1;
	(*ins)->index = total_bytes + 1;
	(*ins)->indir_bytes = IND_SIZE;
	(*ins)->dir_bytes = DIR_SIZE;
	ft_decoding(ins);
	fill_params(ins, split, labels);
	ft_destroy_2d((void**)split);
	free(defix);
	return (1);
}
