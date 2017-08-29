/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fileok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 10:41:57 by akhanye           #+#    #+#             */
/*   Updated: 2017/08/24 11:14:13 by mmayibo          ###   ########.fr       */
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

	if (ft_strcmp(filename + (ft_strlen(filename) - 2), ".s"))
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	return (fd);
}
