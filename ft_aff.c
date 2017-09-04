/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsebaets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 09:32:02 by gsebaets          #+#    #+#             */
/*   Updated: 2017/08/28 10:14:44 by gsebaets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int		ft_aff(t_conv **instruct, int total_bytes, t_label *labels)
{
	char	*defix;

	if (labels)
	{
	}
	if (!(defix = ft_strdefix((*instruct)->line, ' ')))
		return (0);
	if (!((*instruct)->opcode = ft_get_opcode("aff")))
		return (0);
	(*instruct)->bytes = 2;
	(*instruct)->hasencoding = 0;
	(*instruct)->n_params = 1;
	(*instruct)->index = total_bytes + 1;
	ft_decoding(instruct);
	(*instruct)->param[0] = ft_get_reg((*instruct)->line);
	(*instruct)->b_param[0] = T_REG;
	return (1);
}
