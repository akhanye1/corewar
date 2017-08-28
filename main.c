/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 21:04:42 by akhanye           #+#    #+#             */
/*   Updated: 2017/08/28 09:48:16 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int				main(int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		ft_putstr("Usage:\n./asm file_name[.s] ...\n");
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
