/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_shrink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:19:24 by lhorefto          #+#    #+#             */
/*   Updated: 2021/05/25 11:19:25 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_minusflag(char *str, int length)
{
	int	i;
	int	start;

	i = 0;
	start = 0;
	while (str[start] == ' ')
		start++;
	while (start < length)
		str[i++] = str[start++];
	while (i < length)
		str[i++] = ' ';
	return (str);
}

char	*ft_expand(char *old, int *length, int new_length)
{
	char	*new;
	int		i;
	int		j;

	new = (char *)malloc(new_length);
	if (new)
	{
		ft_bzero(new, new_length);
		i = 0;
		j = 0;
		while (i < (new_length - (*length)))
			new[i++] = ' ';
		while (i < new_length)
			new[i++] = old[j++];
	}
	*length = new_length;
	free(old);
	return (new);
}

char	*ft_shrink(char *old, char c, int *length)
{
	char	*new;

	free(old);
	if (c == 'p')
	{
		new = (char *)malloc(3);
		if (!new)
			return (NULL);
		new[0] = '0';
		new[1] = 'x';
		new[2] = 0;
		*length = 2;
	}
	else
	{
		new = (char *)malloc(1);
		if (!new)
			return (NULL);
		new[0] = 0;
		*length = 0;
	}
	return (new);
}
