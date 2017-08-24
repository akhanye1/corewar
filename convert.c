/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 10:30:52 by akhanye           #+#    #+#             */
/*   Updated: 2017/08/24 12:34:34 by mmayibo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

static char		*copy_quote(char *line, int *len)
{
	int i;
	int start;
	int l;

	i = -1;

	while(line[++i] != '"')
		;
	start = i + 1;
	l = 0;
	while (line[++i] && line[i] != '"')
		l++;
	*len = l;
	return (line + start);
}

static int		get_header(int fd, t_asm *data)
{
	char 	*line;
	int		ex;
	int		len;

	data->header.magic = 0xea83f3;
	ft_bzero(data->header.prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(data->header.comment, COMMENT_LENGTH + 1);
	data->header.prog_size = 180;
	ex = 0;
	len = 0;
	while (get_next_line(fd, &line) > 0 && ex < 2)
	{
		if (ft_strncmp(line, ".name", ft_strlen(".name")) == 0)
		{
			ft_strncpy(data->header.prog_name, copy_quote(line, &len), len);
			ex++;
		}
		if (ft_strncmp(line, ".comment", ft_strlen(".comment")) == 0)
		{
			ft_strncpy(data->header.comment, copy_quote(line, &len), len);
			ex++;
		}
	}
	return (ex == 2);
}

static int		add_line(t_conv **data, char *line)
{
	t_conv	*temp;
	int		i;

	if (!(temp = (t_conv*)malloc(sizeof(t_conv))))
		return (0);
	temp->line = ft_strdup(line);
	temp->data = NULL;
	temp->bytes	= 0;
	temp->haslabel = 0;
	temp->opcode = 0;
	temp->hasencoding = 0;
	temp->encoding = 0;
	temp->n_params = 0;
	temp->next = NULL;
	temp->prev = NULL;
	i = -1;
	while (++i < 3)
	{
		b_param[i] = 0;
		param[i] = 0;
	}
}

static int		get_instructions(int fd, t_asm *data)
{
	while (get_next_line(fd, &line) > 0)
	{

	}
	close(fd);
}

int				convert_file(int fd)
{
	char		*line;
	t_asm		data;

	line = NULL;
	data.line = NULL;
	if (!get_header(fd, &data))
		return (0);
	get_instructions(fd, &data);
	write_to_cor(&data);
	return (1);
}
