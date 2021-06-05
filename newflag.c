/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newflag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:25:07 by lhorefto          #+#    #+#             */
/*   Updated: 2021/05/25 15:55:46 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_flags(t_flag *flags)
{
	flags->zero = 0;
	flags->minus = 0;
	flags->prec = -1;
	flags->width = -1;
}

t_flag	*ft_new_flags(void)
{
	t_flag	*new;

	new = (t_flag *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	init_flags(new);
	return (new);
}
