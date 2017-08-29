/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getbytes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmayibo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 15:42:21 by mmayibo           #+#    #+#             */
/*   Updated: 2017/08/29 11:49:18 by pamashil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int			get_bytes_in_line(const char *s, int bytes)
{
	int				index;
	char			*trimmed;
	char			**sp;
	char			**sp2;
	unsigned char	op;

	index = -1;
	sp = ft_strsplit(s, ' '); 
	op = ft_get_opcode(sp[0]);
	sp2 = ft_strsplit(ft_strstr(s, sp[0]) + ft_strlen(sp[0]), SEPARATOR_CHAR);
	bytes = (op == 1 ? 5 : 1);
	if (!(op == 1 || op == 9 || op == 12 || op == 15))
		bytes++; 
	while (op != 1 && sp2[++index])
	{
		trimmed = ft_strtrim(sp2[index]);
		printf("%s\n",trimmed);
		if (trimmed[0] == DIRECT_CHAR)
			bytes += (op < 9 || op == 13 || op == 16 ? DIR_SIZE : IND_SIZE);
		else
			bytes += (trimmed[0] == 'r' ? 1 : IND_SIZE);
		free(trimmed);
	}
	ft_destroy_2d((void**)sp);
	ft_destroy_2d((void**)sp2);
	printf("bytes: %d\n",bytes);
	return (bytes);
}
