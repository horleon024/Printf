/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:24:07 by lhorefto          #+#    #+#             */
/*   Updated: 2021/05/28 10:25:37 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_precorwidth(const char *str, int *i)
{
	int	res;

	res = 0;
	while (ft_isdigit(str[*i]))
		res = res * 10 + (str[(*i)++] - '0');
	(*i)--;
	return (res);
}

static int	set_precorwidth(t_flag *flags, int value, int pos)
{
	if (value < 0 && !pos)
	{
		flags->minus = 1;
		value = -value;
	}
	else if (value < 0 && pos)
	{
		flags->prec = -1;
	}
	if (!pos)
		flags->width = value;
	else if (flags->prec != -1)
		flags->prec = value;
	return (0);
}

static int	is_dot(char c, int *pos)
{
	if (c != '.')
		return (0);
	*pos = 1;
	return (1);
}

t_flag	*ft_get_flags(t_flag *flags, const char *str, va_list *args)
{
	int	pos;
	int	i;

	pos = 0;
	i = 0;
	while (ft_is_in_set(FLAG, str[i]))
	{
		if (str[i] == '0' && !pos)
			flags->zero = 1;
		else if (str[i] == '-')
		{
			pos = 0;
			flags->minus = 1;
		}
		else if (str[i] == '*')
			pos = set_precorwidth(flags, va_arg(*args, int), pos);
		else if ((str[i] >= '1' && str[i] <= '9'))
			pos = set_precorwidth(flags, get_precorwidth(str, &i), pos);
		else if (is_dot(str[i], &pos))
			flags->prec = 0;
		i++;
	}
	return (flags);
}
