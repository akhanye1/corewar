/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 14:15:02 by jbadenho          #+#    #+#             */
/*   Updated: 2017/08/26 08:55:05 by mmayibo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int	ft_and(t_conv *instruct, int total_bytes)
{
	char	*defix;
	char	**split;
	char	*decode;
	int	i;

	if (!(defix = ft_strdefix(instruct->line, ' ')) || !(split = ft_strsplit(defix, ',')))
		return (0);
	if (!(instruct->opcode = ft_get_opcode("and")))
		return (0);
	instruct->bytes = 2;
	instruct->hasencoding = 1;
	instruct->encoding = ft_get_encoding(instruct->line);
	instruct->n_params = 3;
	instruct->index = total_bytes + 1;
	decode = ft_decoding(instruct->line);
	fill_params(instruct, split, decode);
	i = -1;
	while (++i < instruct->n_params)
		instruct->bytes += instruct->b_param[i];
	return (1);
}
