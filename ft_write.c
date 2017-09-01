/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 10:26:34 by akhanye           #+#    #+#             */
/*   Updated: 2017/09/01 10:04:49 by mmayibo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

static void		write_numbers(unsigned char *line, int len, int fd)
{
	int	i;

	i = len;
	while (i--)
		write(fd, &line[i], 1);
}

static void		write_binary(unsigned char *line, int len, int fd)
{
	write(fd, line, len);
}

void 		write_conv_data(t_conv *instruct, int fd)
{
	int 		i;
	unsigned char 		*temp;

	i = -1;
	write(fd, &instruct->opcode,1);
	if (instruct->hasencoding)
		write(fd, &instruct->encoding,1);
	while(++i < instruct->n_params)
	{
		temp = (unsigned char*)&instruct->param[i];
		write_numbers(temp, instruct->b_param[i], fd);	
	}
	temp = 0;
}
void			write_to_cor(t_asm *data)
{
	int				lfd;
	unsigned char	*line;
	unsigned char	byte[5];
	t_conv			*iter;
	char 			*fncor;


	fncor =  get_fn_cor(data->fn);
	ft_bzero(byte, 5);
	if ((lfd = open(fncor, O_CREAT | O_WRONLY , S_IWUSR | S_IRUSR)) == -1)
	{
		ft_putendl("File not created");
		return ;
	}
	line = (unsigned char*)(&data->header.magic);
	write_numbers(line, sizeof(unsigned int), lfd);
	line = (unsigned char*)data->header.prog_name;
	write_binary(line, PROG_NAME_LENGTH, lfd);
	write_binary(byte, 4, lfd);
	line = (unsigned char*)(&data->header.prog_size);
	write_numbers(line, sizeof(unsigned int), lfd);
	line = (unsigned char*)data->header.comment;
	write_binary(line, COMMENT_LENGTH, lfd);
	write_binary(byte, 4, lfd);
	iter = data->line;
	while(iter != NULL)
	{
		write_conv_data(iter, lfd);
		iter = iter->next;
	}
	ft_putstr(data->fn);
	ft_putendl(" successfully converted");
	free(fncor);
	close(lfd);
}
