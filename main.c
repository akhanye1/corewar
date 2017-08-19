/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 21:04:42 by akhanye           #+#    #+#             */
/*   Updated: 2017/08/19 14:38:12 by jngoma           ###   ########.fr       */
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
	start = i;
	l = 0;
	while (line[++i] && line[i] != '"')
		l++;
	*len = l;
	return (line + start);
}

static int		get_header(int fd, t_asm *header)
{
	char 	*line;
	int		ex;
	int		len;

	data->header->magic = COREWAR_EXEC_MAGIC;
	ft_bzero(data->header->prog_name, PROG_NAME_LENGTH);
	ft_bzero(data->header->comment, COMMENT_CHAR);
	ex = 0;
	len = 0;
	while (get_next_line(fd, &line) > 0 && ex < 2)
	{
		if (ft_strncmp(line, ".name", ft_strlen(".name")) == 0)
		{
			ft_strncpy(data->header->prog_name, copy_quote(line, &len), len);
			ft_putendl(data->header->prog_name);
		}
	}
	return (ex == 2);	
}

static int		convert_file(int fd)
{
	char		*line;
	t_asm		data;

	line = NULL;
	data.conv = NULL;
	get_header(fd, &data);
	/*while (get_next_line(fd, &line) > 0)
	{
	}*/
	return (1);
}

int				main(int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		ft_putstr("Usage: asm filename\n");
		return (0);
	}
	if (!(fd = ft_fileok(av[1])))
	{
		ft_putstr("Usage: asm filename\nInvalid file\n");
		return (0);
	}
	if (!convert_file(fd))
		ft_putstr("Error converting file\n");
	return (0);
}
