/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmayibo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 11:08:15 by mmayibo           #+#    #+#             */
/*   Updated: 2017/08/26 09:21:59 by mmayibo          ###   ########.fr       */
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

void	fill_params(t_conv *instruct, char **split, char *decode)
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
			instruct->b_param[i] = instruct->dir_bytes;
			instruct->param[i] = ft_get_dir(split[i]);
		}
		else if (decode[i] == '3')
		{
			instruct->b_param[i] = instruct->indir_bytes;
			instruct->param[i] = ft_get_ind(split[i]);
		}
		i++;
	}
}
