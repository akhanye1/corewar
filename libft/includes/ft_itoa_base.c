/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 12:16:38 by exam              #+#    #+#             */
/*   Updated: 2017/09/05 09:40:47 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		countno(long lvalue, int base)
{
	int count;

	count = 0;
	if (lvalue == 0)
		return (1);
	while (lvalue)
	{
		lvalue /= base;
		count++;
	}
	return (count);
}

char	*ft_itoa_base(int value, int base)
{
	int		digits;
	long	lvalue;
	char	*svalue;
	char	*hexmax;

	if (base < 2 || base > 16)
		return (NULL);
	if (value == -2147483648 && base == 10)
		return ("-2147483648");
	lvalue = (long)(value < 0) ? value * -1 : value;
	digits  = countno(lvalue, base);
	if (base == 10 && value < 0)
		digits++;
	if (!(svalue = (char *)malloc(digits + 1)))
		return (NULL);
	svalue[digits] = '\0';
	hexmax = "0123456789ABCDEF";
	while (digits--)
	{
		if (base == 10 && digits == 0 && value < 0)
			svalue[digits] = '-';
		else
			svalue[digits] = hexmax[lvalue % base];
		lvalue /= base;
	}
	return (svalue);
}
