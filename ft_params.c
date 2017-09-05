/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmayibo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 11:08:15 by mmayibo           #+#    #+#             */
/*   Updated: 2017/09/05 09:32:19 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int		ft_get_dir(char *val)
{
	if (ft_strchr(val, ':') == NULL)
		return (ft_atoi(val + 1));
	else
		return (0);
}

int		ft_get_ind(char *val)
{
	return (ft_atoi(val));
}

int		ft_get_reg(char *val)
{
	int	reg;

	reg = ft_atoi(val + 1);
	return (reg);
}

void	fill_params(t_conv **inst, char **splt, t_label *labels)
{
	int	i;

	i = -1;
	while (++i < (*inst)->n_params)
	{
		if ((*inst)->param_types[i] == 1)
		{
			(*inst)->b_param[i] = 1;
			(*inst)->param[i] = ft_get_reg(splt[i]);
		}
		else if ((*inst)->param_types[i] == 2)
		{
			(*inst)->b_param[i] = (*inst)->dir_bytes;
			if (needslabel(splt[i]))
				(*inst)->param[i] = get_lbl(splt[i], (*inst)->index, labels);
			else
				(*inst)->param[i] = ft_get_dir(splt[i]);
		}
		else if ((*inst)->param_types[i] == 3)
		{
			(*inst)->b_param[i] = (*inst)->indir_bytes;
			if (needslabel(splt[i]))
				(*inst)->param[i] = get_lbl(splt[i], (*inst)->index, labels);
			else
				(*inst)->param[i] = ft_get_ind(splt[i]);
		}
	}
}
