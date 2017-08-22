/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdefix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 18:51:44 by jngoma            #+#    #+#             */
/*   Updated: 2017/08/22 08:37:25 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdefix(char *str, int c)
{
	char	*newstr;
	int		i;
	int		j;
	int		len;

	i = -1;
	while (str[++i] && str[i] != c);
	j = -1;
	len = ft_strlen(str);
	newstr = ft_strnew(len - i);
	while (str[++i] != '\0')
		newstr[++j] = str[i];
	return (newstr);
}
