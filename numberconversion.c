/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numberconversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmayibo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 10:54:02 by mmayibo           #+#    #+#             */
/*   Updated: 2017/08/24 12:08:16 by mmayibo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

unsigned char	bintodec(char *bin_no)
{
	unsigned char 	nbr;
	int 			byte;

	byte = 128;
	nbr = 0;
	while(byte)
	{
		if (*bin_no == '1')
			nbr += byte;
		bin_no++;
		byte /= 2;
	}
	return (nbr);
}
