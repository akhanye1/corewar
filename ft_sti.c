/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmayibo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 09:32:02 by mmayibo           #+#    #+#             */
/*   Updated: 2017/08/24 17:09:02 by mmayibo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

static void	fill_params(t_conv *instruct, char **split, char *decode)
{
	int	i;

	i = 0;
	while(i < 3)
	{
		if (decode[i] == '1')
		{
			instruct->b_param[i] = 1;
			instruct->param[i] = ft_get_reg(split[i]);
		}
		else if (decode[i] == '2')
		{
			instruct->b_param[i] = IND_SIZE;
			instruct->param[i] = ft_get_dir(split[i]);
		}
		else if (decode[i] == '3')
		{
			instruct->b_param[i] = IND_SIZE;
			instruct->param[i] = ft_get_ind(split[i]);
		}
		i++;
	}
}

int		ft_sti(t_conv *instruct)
{
	char	*defix;
	char	**split;
	char	*decode;
	int		i;

	if (!(defix = ft_strdefix(instruct->line, ' ')) ||
			!(split = ft_strsplit(defix, ',')))
		return (0);
	if (!(instruct->opcode = ft_get_opcode("sti")))
		return (0);
	instruct->bytes = 2;
	instruct->hasencoding = 1;
	instruct->encoding = ft_get_encoding(instruct->line);
	instruct->n_params = 3;
	decode = ft_decoding(instruct->line);
	fill_params(instruct, split, decode);
	i = -1;
	while (++i < instruct->n_params)
		instruct->bytes += instruct->b_param[i];
	return (1);
}
