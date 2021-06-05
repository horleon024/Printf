/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:17:00 by lhorefto          #+#    #+#             */
/*   Updated: 2021/05/27 11:45:13 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_alloc_signed(char **str, int value, t_flag *flags)
{
	int	length;
	int	tmp;

	flags->int_value = value;
	length = 1 + (value < 0);
	tmp = value;
	while (tmp >= 10 || tmp <= -10)
	{
		tmp /= 10;
		length++;
	}
	*str = ft_itoa(value);
	if (!(*str))
		return (-1);
	return (length);
}

int	ft_alloc_unsigned(char **str, unsigned int value, t_flag *flags)
{
	int				length;
	unsigned int	tmp;

	flags->uint_value = value;
	length = 1;
	tmp = value;
	while (tmp >= 10)
	{
		tmp /= 10;
		length++;
	}
	*str = ft_uitoa(value);
	if (!(*str))
		return (-1);
	return (length);
}

int	ft_alloc_hex(char **str, char f, unsigned int value, t_flag *flags)
{
	size_t			i;
	int				length;
	unsigned int	tmp;

	flags->uint_value = value;
	length = 1;
	tmp = value;
	while (tmp > 15 && length++)
		tmp /= 16;
	*str = (char *)malloc(length * sizeof(char *));
	if (!(*str))
		return (-1);
	ft_bzero(*str, length);
	if (value == 0)
		(*str)[0] = '0';
	i = length - 1;
	while (value > 0)
	{
		if (f == 'x')
			(*str)[i--] = HEXLOWER[value % 16];
		else if (f == 'X')
			(*str)[i--] = HEXUPPER[value % 16];
		value /= 16;
	}
	return (length);
}

int	ft_alloc_ptr(char **str, void *ptr, t_flag *flags)
{
	int				i;
	int				length;
	long unsigned	tmp;

	flags->ptr = ptr;
	length = 3;
	tmp = (long)ptr;
	while (tmp > 15 && length++)
		tmp /= 16;
	*str = (char *)malloc(length * sizeof(char *));
	if (!(*str))
		return (-1);
	ft_bzero(*str, length);
	(*str)[0] = '0';
	(*str)[1] = 'x';
	if (!ptr)
		(*str)[2] = '0';
	tmp = (long)ptr;
	i = length - 1;
	while (tmp > 0)
	{
		(*str)[i--] = HEXLOWER[tmp % 16];
		tmp /= 16;
	}
	return (length);
}
