/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:51:10 by phperrot          #+#    #+#             */
/*   Updated: 2020/01/16 10:47:03 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_ctoa(char c)
{
	char			*str;

	if (!(str = malloc(sizeof(char) * 2)))
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

char				*ft_strreplace(char *str, char old, char new)
{
	int				i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == old)
			str[i] = new;
		i++;
	}
	return (str);
}

char				*ft_strdup_char(char c)
{
	char			*output;

	if (!(output = malloc(sizeof(char) * 2)))
		return (NULL);
	output[0] = c;
	output[1] = '\0';
	return (output);
}

char				*ft_strjoin_free(char const *s1, char const *s2, int param)
{
	size_t			len;
	char			*out;

	len = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	if (!(out = malloc(sizeof(char) * len)))
		return (NULL);
	ft_strlcpy(out, s1, ft_strlen((char*)s1) + 1);
	ft_strlcat(out, s2, len);
	if (param == 1 || param == 3)
	{
		free((char*)s1);
		s1 = NULL;
	}
	if (param == 2 || param == 3)
	{
		free((char *)s2);
		s2 = NULL;
	}
	return (out);
}

unsigned long		convbase(unsigned long n, t_struct *arg, int i, char **s)
{
	unsigned long	base;

	if (arg->type == 'x' || arg->type == 'X'\
			|| arg->type == 'p')
		base = 16;
	else
		base = ((arg->type == 'o') ? 8 : 10);
	if (n || n == 0)
	{
		if (n >= base)
		{
			i = i + 1;
			convbase(n / base, arg, i, s);
			n = n % base;
		}
		if (n < 10)
			*s = ft_strjoin_free(*s, ft_strdup_char(n + '0'), 3);
		else
			*s = ft_strjoin_free(*s, ft_strdup_char(n - 10 + \
						((arg->type == 'X') ? 'X' - 23 : 'x' - 23)), 3);
	}
	return (0);
}
