/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getbytes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmayibo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 15:42:21 by mmayibo           #+#    #+#             */
/*   Updated: 2017/08/28 15:34:20 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int			get_bytes_in_line(const char *line, int bytes)
{
	int				index;
	char			*trimmed;
	char			**split;
	char			**split2;
	unsigned char	op;

	index = -1;
	split = ft_strsplit(line, ' '); 
	op = ft_get_opcode(split[0]);
	split2 = ft_strsplit(line + ft_strlen(split[0]), SEPARATOR_CHAR);
	bytes = (op == 1 ? 5 : 1);
	if (!(op == 1 || op == 9 || op == 12 || op == 15))
		bytes++; 
	while (op != 1 && split2[++index])
	{
		trimmed = ft_strtrim(split2[index]);
		if (trimmed[0] == DIRECT_CHAR)
			bytes += (op < 9 || op == 13 || op == 16 ? DIR_SIZE : IND_SIZE);
		else
			bytes += (trimmed[0] == 'r' ? 1 : IND_SIZE);
		free(trimmed);
	}
	ft_destroy_2d((void**)split);
	ft_destroy_2d((void**)split2);
	return (bytes);
}
