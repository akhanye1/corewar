/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 09:41:39 by jngoma            #+#    #+#             */
/*   Updated: 2017/08/25 09:45:23 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

static void	fill_params(t_conv *instruct, char **split, char *decode)
{
	int	i;

	i = 0;
	instruct->b_param[i] = IND_SIZE;
	instruct->param[i] = ft_get_dir(split[i]);
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
	if (!(instruct->opcode = ft_get_opcode("zjmp")))
		return (0);
	instruct->bytes = 1;
	instruct->hasencoding = 0;
	instruct->n_params = 1;
	decode = ft_decoding(instruct->line);
	fill_params(instruct, split, decode);
	i = -1;
	while (++i < instruct->n_params)
		instruct->bytes += instruct->b_param[i];
	return (1);
}
