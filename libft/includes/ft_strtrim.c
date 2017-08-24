/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 11:03:14 by gtshekel          #+#    #+#             */
/*   Updated: 2017/08/24 14:09:31 by mmayibo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(char const *s)
{
	char			*ret;
	size_t			len;
	unsigned int	start;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	start = 0;
	while (--len)
	{
		if (s[len] != ' ' && s[len] != '\t' && s[len] != '\n')
		{
			len++;
			break ;
		}
	}
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
		start++;
	if (!(ret = ft_strnew(len > start ? len - start : 0)))
		return (NULL);
	ret = ft_strsub(s, start > len ? 0 : start, len > start ? len - start : 0);
	return (ret);
}
