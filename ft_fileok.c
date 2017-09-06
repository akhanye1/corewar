/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fileok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 10:41:57 by akhanye           #+#    #+#             */
/*   Updated: 2017/09/05 16:08:30 by mmayibo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

/**
 ** This function still needs to be implemeted correctly, this is done just to
 ** make sure the test can be completed
 ** 
 ** it will only check if the file exsist and if it is a .s file for now.
 **/

int		ft_fileok(char *filename)
{
	int	fd;

	if (ft_strcmp(filename + (ft_strlen(filename) - 2), ".s")) //if the string does not match, returns 0
		return (0); //go back to the main
	//if the string does have a .s continue
	fd = open(filename, O_RDONLY); //opens the file and returns it's position in memory
	if (fd == -1) //-1 means that there was an error in opening the file 
		return (0);
	return (fd);
}
