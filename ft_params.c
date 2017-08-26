/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmayibo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 11:08:15 by mmayibo           #+#    #+#             */
/*   Updated: 2017/08/26 08:53:18 by mmayibo          ###   ########.fr       */
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
