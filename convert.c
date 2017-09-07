/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 10:30:52 by akhanye           #+#    #+#             */
/*   Updated: 2017/09/07 13:56:06 by mmayibo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

static char		*copy_quote(char *line, int *len)// The purpose is to convert .s file into binary file
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

static void		init_struct(t_conv *temp, char *line)
{
	int	i;

	i = -1;
	temp->line = ft_strdup(line);
	temp->index = 0;
	temp->bytes	= 0;
	temp->haslabel = 0;
	temp->opcode = 0;
	temp->hasencoding = 0;
	temp->encoding = 0;
	temp->n_params = 0;
	temp->next = NULL;
	temp->dir_bytes = 0;
	temp->indir_bytes = 0;
	i = -1;
	while (++i < 3)
	{
		temp->b_param[i] = 0;
		temp->param[i] = 0;
		temp->param_types[i] = 0;
	}
}

static int		add_line(t_conv **data, char *line)
{
	t_conv	*temp;
	t_conv	*iter;

	if (!(temp = (t_conv*)malloc(sizeof(t_conv))))
		return (0);
	init_struct(temp, line);
	if (!(*data))
		(*data) = temp;
	else
	{
		iter = (*data);
		while (iter->next)
			iter = iter->next;
		iter->next = temp;
	}
	return (1);
}

static int	count_all_bytes(t_asm *data)
{
	int		b;
	t_conv	*iter;

	b = 0;
	if (!data->line)
		return (b);
	iter = data->line;
	while (iter)
	{
		b += iter->bytes;
		iter = iter->next;
	}
	return (b);
}

static int		get_file(int fd, t_asm *data)
{
	char 	*line;// Stores info about a line read from .s file
	int		len;// 
	char	*totrim;
	char	*temp;

	line = NULL;
	data->header.magic = 0xea83f3;
	ft_bzero(data->header.prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(data->header.comment, COMMENT_LENGTH + 1);
	data->header.prog_size = 0;
	len = 0;
	while (get_next_line(fd, &totrim) > 0)
	{
		if (!(line = ft_strtrim(totrim)))
			return (0);
		if (ft_strchr(line, COMMENT_CHAR))
		{
			temp = ft_strnew(ft_strlen(line));
			ft_strncpy(temp, line, (ft_strchr(line, COMMENT_CHAR) - line));
			free(line);
			line = ft_strtrim(temp);
			free(temp);
		}
		if (ft_strncmp(line, ".name", ft_strlen(".name")) == 0)
			ft_strncpy(data->header.prog_name, copy_quote(line, &len), len);
		else if (ft_strncmp(line, ".comment", ft_strlen(".comment")) == 0)
			ft_strncpy(data->header.comment, copy_quote(line, &len), len);
		else if (ft_strlen(line) > 0 && line[0] != '#' && line[0] != '.')
			add_line(&(data->line), line);
		free(line);
	}
	return (1);
}

int update_conv(t_conv **line, int total_bytes, t_label *labels, mne_func *functs)
{
	char		*newstr;
	char 		*mne;
	int 		i;

	if (!(newstr = ft_strtrim((*line)->line)))
		return (0);
	if ((*line)->line)
		free((*line)->line);
	i = -1;
	(*line)->line = newstr;
	while(newstr[++i] != ' ' && newstr[i] != '\t')
		;
	mne = ft_strndup(newstr, i);
	//this runs the appropiate functions 
	functs[(int)ft_get_opcode(mne) - 1](line, total_bytes, labels);
	free(mne);
	return (0);

}

int				convert_file(int fd, char debug, char *fn)
{
	t_asm		data; //Stores information about the file.Example : The header,linked list of the lines and the file name.
	t_label		/**labels;*/
	int			total_bytes;//Stores the total bytes that are contained in the .core file
	t_conv 		*iter;// Its a struct that stores info about the iterration of linked list 
	mne_func	functs[16];//It holds all the pointers to the mneunonic e.g sti, add, st 

	total_bytes = 0;// Total from our functions e.g sti. st, add
	data.fn = fn;// Filename
	data.line = NULL;
	data.debug = debug;
	labels = NULL;
	if (!get_file(fd, &data))// Get next line....Starting to read from a .s file
		return (0);
	if (data.debug)
	{
		ft_putendl("\n\nDATA IN BUFFER\n");
		iter = data.line;
		while (iter)
		{
			ft_putendl(iter->line);
			iter = iter->next;
		}
		ft_putline();
	}
	iter = data.line;
	create_all_lbls(&labels, &iter, total_bytes);
	iter = data.line;
	fill_opcode_array(functs);
	if (data.debug)
		ft_putendl("Debug Information:");
	while (iter) // it iterates the linked list
	{
		remove_tabs(iter->line);
		if (data.debug && iter->line && ft_strlen(iter->line))
			show_conv_before(iter->line);
		if (iter->line && ft_strlen(iter->line))
		{
			//each structure is updated
			update_conv(&iter, total_bytes, labels, functs);
			if (data.debug)
				show_hex(iter);
			if (ft_strlen(iter->line) > 0)
				total_bytes += iter->bytes;
		}
		iter = iter->next;
	}
	data.header.prog_size = (unsigned int)count_all_bytes(&data);
	write_to_cor(&data);
	return (1);
}
