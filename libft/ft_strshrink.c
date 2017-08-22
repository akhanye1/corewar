/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strshrink.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 18:52:40 by jngoma            #+#    #+#             */
/*   Updated: 2017/08/21 18:53:36 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		spaceless_len(char *str)
{
	int		i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == 32)
			i--;
		i++;
	}
	return (i);
}

char	*ft_strshrink(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*newstr;

	i = -1;
	j = -1;
	len = spaceless_len(str);
	newstr = ft_strnew((unsigned int)len);
	while (str[++i] != '\0')
	{
		if (str[i] == 32)
		{
			while (str[i] == 32)
				i++;
		}
		newstr[++j] = str[i];
	}
	return (newstr);
}
