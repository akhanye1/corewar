/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmayibo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 11:11:39 by mmayibo           #+#    #+#             */
/*   Updated: 2017/08/25 10:01:55 by mmayibo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strndup(const char *s, int len)
{
	char	*s2;

	s2 = (char *)ft_memalloc(len + 1);
	if (s2 == NULL)
		return (NULL);
	ft_strncpy(s2, s, len);
	return (s2);
}
