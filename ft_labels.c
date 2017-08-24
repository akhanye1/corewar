/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_labels.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmayibo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 13:45:46 by mmayibo           #+#    #+#             */
/*   Updated: 2017/08/24 16:07:21 by mmayibo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int			ft_is_label_only(char *line)
{
	char	**split;

	if (ft_strchr(line, ':'))
	{
		split = ft_strsplit(line, ':');
		if (ft_items_in_grid((void **)split) == 1)
		{
			ft_destroy_2d((void **)split);
			return (1);
		}
		else
		{
			ft_destroy_2d((void **)split);
			return (0);
		}
	}
	else
		return (0);
}

int			ft_contains_label(char *line)
{
	char **split;

	split = ft_strsplit(line , ' ');
	if (ft_strchr(split[0], ':'))
	{
		ft_destroy_2d((void **)split);
		return (1);
	}
	return (0);
}

t_label		*create_label(char **line, int total_bytes)
{
	t_label		*label;
	char		**split;
	char		*tmp;

	if (!(label = (t_label*)malloc(sizeof(t_label))))
		return (NULL);
	split = ft_strsplit(*line, ':');
	label->name = ft_strdup(split[0]);
	label->index = total_bytes + 1;
	tmp = ft_strtrim(*line);
	free(*line);
	*line = ft_strsub(tmp, ft_strlen(label->name) + 1, ft_strlen(tmp) - ft_strlen(label->name) - 1);
	free(tmp);
	ft_destroy_2d((void **)split);
	return (label);
}

void		add_label(t_label **label, t_label *new)
{
	new->next = *label;
	*label = new;
}

/*void		delete_convo(t_conv **lst, t_conv *convo)
{
	t_conv *hold;

	hold
	while (*lst)
	{

		if (*lst == convo)
		{

		}
	}
*/
