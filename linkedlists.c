/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:15:45 by lhorefto          #+#    #+#             */
/*   Updated: 2021/05/25 11:15:46 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_str	*ft_str_last(t_str *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

int	ft_str_clear(t_str **lst)
{
	t_str	*tmp;

	if (!*lst)
		return (0);
	while (lst && *lst)
	{
		if ((*lst)->content)
			free((*lst)->content);
		tmp = (*lst)->next;
		free(*lst);
		(*lst) = tmp;
	}
	*lst = NULL;
	return (0);
}

t_str	*ft_str_new(void *content, int length)
{
	t_str	*new;

	new = (t_str *)malloc(sizeof(t_str));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->content = content;
	new->length = length;
	return (new);
}
