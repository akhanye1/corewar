/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 21:04:42 by akhanye           #+#    #+#             */
/*   Updated: 2017/08/17 10:41:42 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int				main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr("Usage: asm filename\n");
		return (0);
	}
	if (!ft_fileok(av[1]))
	{
		ft_putstr("Usage: asm filename\nInvalid file\n");
		return (0);
	}
	return (0);
}
