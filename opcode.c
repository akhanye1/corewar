/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmayibo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 13:30:27 by mmayibo           #+#    #+#             */
/*   Updated: 2017/08/28 16:30:59 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

unsigned char		check_sec_instructs(char *str)
{
	unsigned char	opcode;

	opcode = 0;
	if (ft_strequ(str, "zjmp"))
		opcode = 9;
	else if (ft_strequ(str, "ldi"))
		opcode = 10;
	else if (ft_strequ(str, "sti"))
		opcode = 11;
	else if (ft_strequ(str, "fork"))
		opcode = 12;
	else if (ft_strequ(str, "lld"))
		opcode = 13;
	else if (ft_strequ(str, "lldi"))
		opcode = 14;
	else if (ft_strequ(str, "lfork"))
		opcode = 15;
	else if (ft_strequ(str, "aff"))
		opcode = 16;
	return (opcode);
}

unsigned char		check_first_instructs(char *str)
{
	unsigned char	opcode;

	opcode = 0;
	if (ft_strequ(str, "live"))
		opcode = 1;
	else if (ft_strequ(str, "ld"))
		opcode = 2;
	else if (ft_strequ(str, "st"))
		opcode = 3;
	else if (ft_strequ(str, "add"))
		opcode = 4;
	else if (ft_strequ(str, "sub"))
		opcode = 5;
	else if (ft_strequ(str, "and"))
		opcode = 6;
	else if (ft_strequ(str, "or"))
		opcode = 7;
	else if (ft_strequ(str, "xor"))
		opcode = 8;
	return (opcode);
}

void fill_opcode_array(mne_func *func_array)
{
	func_array[0] = ft_live;
	func_array[1] = ft_sti;
	func_array[2] = ft_sti;
	func_array[3] = ft_sti;
	func_array[4] = ft_sti;
	func_array[5] = ft_sti;
	func_array[6] = ft_sti;
	func_array[7] = ft_sti;
	func_array[8] = ft_sti;
	func_array[9] = ft_sti;
	func_array[10] = ft_sti;
	func_array[11] = ft_sti;
	func_array[12] = ft_sti;
	func_array[13] = ft_sti;
	func_array[14] = ft_sti;
	func_array[15] = ft_sti;
}
/**
 ** send only the code to this function not the entire line
 ** for example (live, or)
**/

unsigned char		ft_get_opcode(char *str)
{
	unsigned char opcode;

	if ((opcode = check_first_instructs(str)))
		;
	else if ((opcode = check_sec_instructs(str)))
		;
	return (opcode);
}
