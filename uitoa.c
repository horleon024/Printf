/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:37:05 by lhorefto          #+#    #+#             */
/*   Updated: 2021/05/23 12:13:54 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*check_min_int(int n, int *error_nbr)
{
	char	*result;

	result = NULL;
	if (n == -2147483648)
	{
		result = ft_strdup("-2147483648");
		if (result == NULL)
			*error_nbr = 1;
	}
	return (result);
}

static int	check_str_len(int digits)
{
	size_t	nbr_of_digits;

	if (digits == 0)
		return (1);
	nbr_of_digits = 0;
	while (digits > 0)
	{
		digits = digits / 10;
		nbr_of_digits++;
	}
	return (nbr_of_digits);
}

static void	conversion_itoa(int strlen, int is_negative, int n, char *result)
{
	char	temp;

	result[strlen] = '\0';
	strlen--;
	while (strlen > is_negative)
	{
		temp = (n % 10) + '0';
		result[strlen] = temp;
		n = n / 10;
		strlen--;
	}
	result[strlen] = n + '0';
	if (is_negative)
		result[0] = '-';
}

char	*ft_itoa(int n)
{
	int		strlen;
	int		is_negative;
	char	*result;
	int		error_nbr;

	strlen = 0;
	is_negative = 0;
	error_nbr = 0;
	result = check_min_int(n, &error_nbr);
	if ((result != NULL) || (error_nbr == 1))
		return (result);
	if (n < 0)
	{
		strlen++;
		n *= -1;
		is_negative = 1;
	}
	strlen += check_str_len(n);
	result = (char *)malloc(strlen + 1);
	if (result == NULL)
		return (result);
	conversion_itoa(strlen, is_negative, n, result);
	return (result);
}

char	*ft_uitoa(unsigned int n)
{
	char			*str;
	size_t			length;
	unsigned int	tmp;

	tmp = n;
	length = (n == 0);
	while (tmp)
	{
		length++;
		tmp /= 10;
	}
	str = ft_calloc(length + 1, sizeof(char));
	if (!str)
		return (str);
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[--length] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
