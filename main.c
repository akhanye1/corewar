/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 21:04:42 by akhanye           #+#    #+#             */
/*   Updated: 2017/08/19 16:34:45 by jngoma           ###   ########.fr       */
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

	//Todo Program Size
	//0xf383ae
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

static void		write_to_cor(t_asm *data)
{
	int				lfd;
	unsigned char	*line;

	if ((lfd = open("test.cor", O_CREAT | O_WRONLY)) == -1)
	{
		ft_putendl("File not created");
		return ;
	}
	line = (unsigned char*)(&data->header.magic);
	//write_binary(line, sizeof(unsigned int), lfd);
	write_numbers(line, sizeof(unsigned int), lfd);
	line = (unsigned char*)data->header.prog_name;
	write_binary(line, PROG_NAME_LENGTH + 4, lfd);
	line = (unsigned char*)(&data->header.prog_size);
	write_numbers(line, sizeof(unsigned int), lfd);
	line = (unsigned char*)data->header.comment;
	write_binary(line, COMMENT_LENGTH, lfd);
	close(lfd);
}

static int		convert_file(int fd)
{
	char		*line;
	t_asm		data;

	line = NULL;
	data.conv = NULL;
	if (!get_header(fd, &data))
	{
		ft_putendl("Fail");
		return (0);
	}
	write_to_cor(&data);
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
	close(fd);
	return (0);
}
