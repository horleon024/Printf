/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 10:39:02 by lhorefto          #+#    #+#             */
/*   Updated: 2021/05/25 15:56:05 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define HEXLOWER "0123456789abcdef"
# define HEXUPPER "0123456789ABCDEF"
# define CONV "cspdiuxX%"
# define FLAG "0123456789-.*"

typedef struct s_flag
{
	int				minus;
	int				zero;
	char			*str;
	void			*ptr;
	char			c;
	unsigned int	uint_value;
	int				int_value;
	int				prec;
	int				width;
}					t_flag;

typedef struct s_str
{
	int				length;
	char			*content;
	struct s_str	*next;
}					t_str;

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
int		ft_isdigit(int c);
int		ft_is_in_set(char *set, int c);
t_str	*ft_str_add_back(t_str **alst, char *content, int length);
t_str	*ft_str_last(t_str *lst);
int		ft_str_clear(t_str **lst);
t_str	*ft_str_new(void *content, int length);
int		ft_str_iter(t_str *lst, void (*f)(t_str*));
void	ft_str_write(t_str *lst);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
t_flag	*ft_new_flags(void);
t_flag	*ft_get_flags(t_flag *flags, const char *str, va_list *args);
char	*ft_minusflag(char *str, int length);
char	*ft_expand(char *old, int *length, int new_length);
char	*ft_shrink(char *old, char c, int *length);
int		ft_is_str(int c);
char	*ft_zero_pad(char *str, char c, int length, int max);
char	*ft_transfrom(char **old, char c, t_flag *flags, int *length);
int		ft_alloc_signed(char **str, int value, t_flag *flags);
int		ft_alloc_unsigned(char **str, unsigned int value, t_flag *flags);
int		ft_alloc_hex(char **str, char f, unsigned int value, t_flag *flags);
int		ft_alloc_ptr(char **str, void *ptr, t_flag *flags);
int		ft_alloc_char(char **str, int c, t_flag *flags);
int		ft_alloc_str(char **str, char *src, t_flag *flags);

#endif