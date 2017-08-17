/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 21:04:42 by akhanye           #+#    #+#             */
/*   Updated: 2017/08/17 11:16:18 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

static int		convert_file(int fd)
{
	char	*line;
	t_asm	data;

	line = NULL;
	data.conv = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		
	}
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
