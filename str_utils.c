/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 12:16:48 by lhorefto          #+#    #+#             */
/*   Updated: 2021/05/23 12:16:49 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	j;

	result = (char *)malloc(len + 1);
	if (!s || !result)
		return (0);
	i = start;
	j = 0;
	while (i < ft_strlen(s) && j < len)
		result[j++] = s[i++];
	result[j] = 0;
	return (result);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dest;

	dest = NULL;
	i = 0;
	dest = (char *)malloc(ft_strlen(src) + 1);
	if (dest == NULL)
		return (0);
	while (src[i])
	{
		dest[i] = ((char *)src)[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == 0)
		return (ptr);
	ft_bzero(ptr, size * nmemb);
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
