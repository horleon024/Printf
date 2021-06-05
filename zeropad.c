/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zeropad.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:27:17 by lhorefto          #+#    #+#             */
/*   Updated: 2021/05/25 18:28:02 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*zero_pad_void(char *str, int length, int max)
{
	int	i;
	int	min;

	min = length - max;
	i = 0;
	while (str[i] != 'x')
	{
		if (i >= min)
			str[i] = '0';
		i++;
	}
	if (i >= min)
	{
		str[i] = '0';
		str[1] = 'x';
	}
	return (str);
}

static int	check_for_neg(char c, char d, int *is_neg)
{
	if ((c == 'd' || c == 'i') && d == '-')
	{
		*is_neg = 1;
		return (1);
	}
	return (0);
}

char	*ft_zero_pad(char *str, char c, int length, int max)
{
	int	i;
	int	is_neg;
	int	min;

	if (c == 'p')
		return (zero_pad_void(str, length, max));
	is_neg = 0;
	min = length - max;
	i = 0;
	while (i < length && (str[i] == ' ' || check_for_neg(c, str[i], &is_neg)))
	{
		if (i >= min)
			str[i] = '0';
		i++;
	}
	if (is_neg)
	{
		i = 0;
		while (str[i] == ' ')
			i++;
		str[i] = '-';
	}
	return (str);
}
