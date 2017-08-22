/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdefix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 18:51:44 by jngoma            #+#    #+#             */
/*   Updated: 2017/08/21 18:52:20 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_defix(char *str, int n)
{
	char	*newstr;
	int		i;
	int		j;
	int		len;

	i = n - 1;
	j = -1;
	len = ft_strlen(str);
	newstr = (char *)malloc((len - i) + 1);
	while (str[i++] != '\0')
	{
		newstr[++j] = str[i];
	}
	return (newstr);
}
