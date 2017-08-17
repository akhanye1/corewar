/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 13:24:06 by akhanye           #+#    #+#             */
/*   Updated: 2017/06/10 14:33:01 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char		*ft_strtrim(const char *str)
{
	int		b;
	int		e;
	char	*tmp;

	if (str == NULL)
		return (NULL);
	b = ft_skipempty(str);
	e = ft_lastal(str) + 1;
	tmp = (char *)malloc(sizeof(char) * ((e - b) + 1));
	if (tmp == NULL)
		return (NULL);
	if (e == 1)
	{
		tmp[0] = '\0';
		return (tmp);
	}
	ft_strcpysub(tmp, str, b, ((e - b)));
	tmp[(e - b)] = '\0';
	return (tmp);
}
