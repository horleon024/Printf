/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:17:07 by lhorefto          #+#    #+#             */
/*   Updated: 2021/05/25 11:17:08 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_alloc_char(char **str, int c, t_flag *flags)
{
	flags->c = c;
	*str = (char *)malloc(1);
	if (!(*str))
		return (-1);
	(*str)[0] = (unsigned char)c;
	return (1);
}

int	ft_alloc_str(char **str, char *src, t_flag *flags)
{
	int	length;

	if (!src)
	{
		if (flags->prec == -1 || flags->prec > 5)
			src = "(null)";
		else
			src = "";
	}
	flags->str = src;
	length = ft_strlen(src);
	*str = ft_strdup(src);
	if (!(*str))
		return (-1);
	return (length);
}
