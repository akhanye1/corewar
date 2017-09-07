/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 21:04:42 by akhanye           #+#    #+#             */
/*   Updated: 2017/09/07 13:56:08 by mmayibo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int				main(int ac, char **av) // The purpose of the main is to run two  functions.Check if the file .s is ok and the other one is to convert the actuall .s file into .core file

{
	int		fd; //file descriptor which points to a file in memory

		/*char	debug;

	if (((ac == 3 && ft_strcmp(av[2], "-v")) &&
				(ac <= 3 && ft_strcmp(av[2], "-v")))
				|| (ac == 1))
	{
		ft_putstr("Usage: asm <filename> [-v]\n");
		return (0);
	}
	debug = (ac == 3) ? 1 : 0;
	*/
	if (!(fd = ft_fileok(av[1]))) //fileok checks if the file doesn't have any errors and prints the appropiate error...see pdf asm beforewe convert the file	
	{
		ft_putstr("Usage: asm filename\nInvalid file\n");
		return (0);
	}

	ft_putstr("Assembling ");//starting to assemble
	ft_putendl(av[1]);// file name string
	
	if (!convert_file(fd, debug, av[1]))  //av[1] is the name of the file in a raw string
		ft_putstr("Error converting file\n"); 
	close(fd);//closing the previously opened file
	return (0);
}

