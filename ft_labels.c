/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_labels.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmayibo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 13:45:46 by mmayibo           #+#    #+#             */
/*   Updated: 2017/08/28 16:27:01 by gtshekel         ###   ########.fr       */
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
	int			lbl_len;

	if (!(label = (t_label*)malloc(sizeof(t_label))))
		return (NULL);
	split = ft_strsplit(*line, ':');
	label->name = ft_strdup(split[0]);
	label->index = total_bytes + 1;
	label->next = NULL;
	lbl_len = ft_strlen(label->name);
	tmp = ft_strtrim(*line);
	free(*line);
	*line = ft_strsub(tmp, lbl_len + 1, ft_strlen(tmp) - lbl_len - 1);
	free(tmp);
	ft_destroy_2d((void **)split);
	return (label);
}

void		add_label(t_label **label, t_label *new)
{
	new->next = *label;
	*label = new;
}

int			needslabel(char *split)
{
	if (ft_strchr(split, ':'))
		return (1);
	return (0);
}

int			get_lbl(char *item, int index, t_label *labels)
{
	char	**split;
	int		num;
	t_label	*tmp;

	tmp = labels;
	split = ft_strsplit(item, ':');
	num = ft_items_in_grid((void**)split);
	while (tmp)
	{
		if ((ft_strequ(tmp->name, split[num == 1 ? 0 : 1])))
		{
			ft_destroy_2d((void**)split);
			return (tmp->index - index);
		}
		tmp = tmp->next;
	}
	ft_destroy_2d((void**)split);
	return (index);
}

void		create_all_lbls(t_label **labels, t_conv **iter, int total_bytes)
{
	while (*iter)
	{
		if (ft_is_label_only((*iter)->line) || ft_contains_label((*iter)->line))
		{
			if (*labels == NULL)
				*labels = create_label(&(*iter)->line, total_bytes);
			else
				add_label(labels, create_label(&(*iter)->line, total_bytes));
			if (ft_strequ((*iter)->line, ""))
				*iter = (*iter)->next;
		}
		total_bytes += get_bytes_in_line((*iter)->line, 0);
		*iter = (*iter)->next;
	}
}
