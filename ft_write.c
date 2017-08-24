/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 10:26:34 by akhanye           #+#    #+#             */
/*   Updated: 2017/08/21 10:30:34 by akhanye          ###   ########.fr       */
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

void			write_to_cor(t_asm *data)
{
	int				lfd;
	unsigned char	*line;
	unsigned char	byte[4];

	ft_bzero(byte, 4);
	if ((lfd = open("test.cor", O_CREAT | O_WRONLY , S_IWUSR | S_IRUSR)) == -1)
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
	close(lfd);
}
