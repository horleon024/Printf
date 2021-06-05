/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:27:09 by lhorefto          #+#    #+#             */
/*   Updated: 2021/05/28 10:36:23 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*shrink_if_needed(t_flag *flags, char c, char *new, int *length)
{
	if ((c != 'p' || !(long)flags->ptr)
		&& ((c != 'd' && c != 'i') || !flags->int_value)
		&& ((c != 'u' && c != 'x' && c != 'X') || !flags->uint_value))
		new = ft_shrink(new, c, length);
	return (new);
}

static void	add_zeros_alignleft(t_flag *flags, char *str, char c, int *length)
{
	if (flags->minus)
		ft_minusflag(str, *length);
	else if (flags->zero && flags->prec)
	{
		if (flags->prec >= 0)
			ft_zero_pad(str, c, *length, flags->prec);
		else
			ft_zero_pad(str, c, *length, *length);
	}
}

static char	*expand_if_needed(char **str, t_flag *flags, char c, int *length)
{
	int	add;

	if (flags->prec >= *length && c != '%')
	{
		add = 0;
		if ((c == 'd' || c == 'i') && flags->int_value < 0)
			add++;
		if (c == 'p')
			add += 2;
		*str = ft_expand(*str, length, flags->prec + add);
		if (!(*str))
			return (NULL);
	}
	return (*str);
}

char	*ft_transfrom(char **old, char c, t_flag *flags, int *length)
{
	char	*new;

	new = *old;
	if (flags->prec == 0 && !ft_is_str(c))
		new = shrink_if_needed(flags, c, new, length);
	if (c == 's' && flags->prec >= 0 && flags->prec < *length)
		*length = flags->prec;
	else if (!ft_is_str(c) && flags->prec >= 0 && ft_is_in_set(CONV, c))
	{
		if (!expand_if_needed(&new, flags, c, length))
			return (NULL);
		if (flags->prec > 0)
			ft_zero_pad(new, c, *length, *length);
	}
	if (flags->width > 0 && (*length) < flags->width && c != '%')
	{
		new = ft_expand(new, length, flags->width);
		if (!new)
			return (NULL);
		add_zeros_alignleft(flags, new, c, length);
	}
	*old = new;
	return (new);
}
