/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 14:36:40 by gtshekel          #+#    #+#             */
/*   Updated: 2017/09/05 12:42:08 by mmayibo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

void		destroy_labels(t_label *labels)
{
	t_label	*tmp;

	while (labels)
	{
		tmp = labels;
		labels = labels->next;
		free(tmp->name);
		tmp->name = NULL;
		free(tmp);
		tmp = NULL;		
	}
}


void		destroy_lst_instruct(t_conv *data)
{
	t_conv	*tmp;

	while (data)
	{
		tmp = data;
		data = data->next;
		tmp->next = NULL;
		free(tmp->line);
		tmp->line = NULL;
		free(tmp);
		tmp = NULL;
	}
}

void destroy_data(t_asm *data)
{
	if (data)
		if (data->line)
			destroy_lst_instruct(data->line);
}

