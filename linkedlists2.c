/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlists2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:15:32 by lhorefto          #+#    #+#             */
/*   Updated: 2021/05/25 11:21:40 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str_iter(t_str *lst, void (*f)(t_str*))
{
	int	sum;

	sum = 0;
	if (!f)
		return (0);
	while (lst)
	{
		(*f)(lst);
		sum += lst->length;
		lst = lst->next;
	}
	return (sum);
}

void	ft_str_write(t_str *lst)
{
	if (lst && lst->length >= 0)
		write(1, lst->content, lst->length);
}

t_str	*ft_str_add_back(t_str **alst, char *content, int length)
{
	t_str	*last;
	t_str	*new;

	if (!content || length < 0)
		return (NULL);
	new = ft_str_new(content, length);
	if (!new)
	{
		free(content);
		return (NULL);
	}
	if (*alst)
	{
		last = ft_str_last(*alst);
		last->next = new;
	}
	else
		*alst = new;
	return (new);
}
