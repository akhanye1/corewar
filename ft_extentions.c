/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extentions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmayibo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 09:31:54 by mmayibo           #+#    #+#             */
/*   Updated: 2017/09/05 09:28:44 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

char		*get_fn_with_ext(char *fn)
{
	char		*name;
	char		*end;
	int			index;

	index = 0;
	if (!(end = ft_strrchr(fn, '.')))
		return (NULL);
	while (&fn[index] != end)
		index++;
	if (!(name = ft_strndup(fn, index)))
		return (NULL);
	return (name);
}

char		*get_fn_cor(char *fn)
{
	char		*name_no_ext;
	char		*name_cor;

	if (!(name_no_ext = get_fn_with_ext(fn)))
		return (NULL);
	if (!(name_cor = ft_strjoin(name_no_ext, ".cor")))
		return (NULL);
	free(name_no_ext);
	return (name_cor);
}
