/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:24:19 by lhorefto          #+#    #+#             */
/*   Updated: 2021/05/25 15:40:17 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_memory(char **str, char format, va_list *args, t_flag *flags)
{
	if (format == 'd' || format == 'i')
		return (ft_alloc_signed(str, va_arg(*args, int), flags));
	else if (format == 'x' || format == 'X')
		return (ft_alloc_hex(str, format, va_arg(*args, unsigned int), flags));
	else if (format == 'u')
		return (ft_alloc_unsigned(str, va_arg(*args, unsigned int), flags));
	else if (format == 's')
		return (ft_alloc_str(str, va_arg(*args, char *), flags));
	else if (format == 'c')
		return (ft_alloc_char(str, va_arg(*args, int), flags));
	else if (format == 'p')
		return (ft_alloc_ptr(str, va_arg(*args, void *), flags));
	return (ft_alloc_char(str, format, flags));
}

static char	*solve_flags(char *str, char c, int *length, va_list *args)
{
	char	*res;
	t_flag	*flags;

	flags = ft_new_flags();
	res = NULL;
	if (!str || !flags)
		return (NULL);
	ft_get_flags(flags, str, args);
	free(str);
	*length = get_memory(&res, c, args, flags);
	if (*length < 0 || !res)
	{
		free(flags);
		return (NULL);
	}
	if (!ft_transfrom(&res, c, flags, length))
	{
		free(flags);
		return (NULL);
	}
	free(flags);
	return (res);
}

static char	*add_tolist(t_str **res, const char *str, int length, va_list *args)
{
	int		rlength;
	char	*ret;

	ret = solve_flags(ft_substr(str, 0, length), str[length], &rlength, args);
	if (!ret)
		return (NULL);
	if (!ft_str_add_back(res, ret, rlength))
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

static int	get_substr(const char *str, int i, t_str **res, va_list *args)
{
	int	start;

	start = i;
	while (str[i] && str[i] != '%')
		i++;
	if (i - start > 0
		&& !ft_str_add_back(res, ft_substr(str, start, i - start), i - start))
		return (-1);
	if (str[i] == '%')
	{
		start = ++i;
		if (str[i])
		{
			while (ft_is_in_set(FLAG, str[i]))
				i++;
			if (!add_tolist(res, str + start, i - start, args))
				return (-1);
			i++;
		}
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_str	*res;
	int		i;

	if (!format)
		return (0);
	res = NULL;
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		i = get_substr(format, i, &res, &args);
		if (i < 0)
		{
			va_end(args);
			return (ft_str_clear(&res));
		}
	}
	va_end(args);
	i = ft_str_iter(res, &ft_str_write);
	ft_str_clear(&res);
	return (i);
}
