/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_read_param2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:03:09 by phperrot          #+#    #+#             */
/*   Updated: 2020/02/01 16:37:00 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				check_double_percent(char *str, int *i)
{
	int			check;

	check = 0;
	while (str[*i] == '%' && str[*i + 1] == '%')
	{
		ft_putchar('%');
		*i = *i + 2;
		check++;
	}
	if (*i >= (int)ft_strlen(str))
		*i = *i - 1;
	return (check);
}

int				check_flag(char *str, int i, t_struct **param, int k)
{
	int			j;

	j = i;
	if (ft_test_presence_char(str[i], SET_FLAG))
	{
		while (ft_test_presence_char(str[i], SET_FLAG))
			i++;
		if (!((*param)->flag = malloc(sizeof(char) * (i - j + 1))))
			return (0);
		while (k < i - j)
		{
			(*param)->flag[k] = str[j + k];
			k++;
		}
		(*param)->flag[k] = '\0';
	}
	if (str[i] == '*')
	{
		(*param)->pound_flag = 1;
		i++;
	}
	if (ft_strchr((*param)->flag, '-') != 0)
		(*param)->flag = ft_strreplace((*param)->flag, '0', 'e');
	return (i);
}

int				check_width(char *str, int i, t_struct **param)
{
	int			j;
	int			k;
	char		*tmp1;

	j = i;
	while (str[i] == '0')
		i++;
	if (ft_isdigit(str[i]))
	{
		while (ft_isdigit(str[i]))
			i++;
		k = 0;
		if (!((tmp1 = malloc(sizeof(char) * (i - j + 1)))))
			return (0);
		while (k < i - j)
		{
			tmp1[k] = str[j + k];
			k++;
		}
		tmp1[k] = '\0';
		((*param)->min_width) = ft_atoi(tmp1, 'd');
		free(tmp1);
	}
	return (i);
}

int				check_prec_type(char *s, int i, t_struct **par, int k)
{
	int			j;

	j = i;
	if (s[i] == '.')
	{
		i++;
		while ((ft_isdigit(s[i]) || s[i] == '*') && s[i] != '\0')
			i++;
		if (!((*par)->prec = malloc(sizeof(char) * (i - j + 1))))
			return (0);
		while (k < i - j)
		{
			(*par)->prec[k] = s[j + k];
			k++;
		}
		(*par)->prec[k] = '\0';
	}
	if (ft_test_presence_char(s[i], SET_CONVERSION))
		(*par)->type = s[i];
	if (ft_test_presence_char(s[i], SET_CONVERSION))
		i++;
	if ((*par)->type == 'c' || (*par)->type == '%')
		(*par)->prec = "\0";
	return (i);
}
