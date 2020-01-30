/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_read_param2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:03:09 by phperrot          #+#    #+#             */
/*   Updated: 2020/01/30 18:11:18 by phperrot         ###   ########.fr       */
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
	return (check);
}

int				check_flag(char *str, int i, t_struct **param)
{
//	char		*tmp;
	int			j;
	int			k;
	int			len;

	j = i;
	if (ft_test_presence_char(str[i], SET_FLAG))
	{
		while (ft_test_presence_char(str[i], SET_FLAG))
		{
/*			tmp = ft_add_char((*param)->flag, str[i]);
			(*param)->flag = tmp;
			free(tmp);
			tmp = NULL;
*/			i++;
		}
/*		tmp = ft_add_char((*param)->flag, '\0');
		(*param)->flag = tmp;
		free(tmp);
		tmp = NULL;
*/	len = i - j;
	k = 0;
	if (!((*param)->flag = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (k < len)
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
	char		*tmp1;
	char		*tmp2;
	int			j;
	int			k;
	int			len;

	j = i;
	tmp1 = NULL;
	tmp2 = NULL;
	while (str[i] == '0')
		i++;
	if (ft_isdigit(str[i]))
	{
		while (ft_isdigit(str[i]))
		{
	/*		tmp2 = tmp1;
			free(tmp1);
			tmp1 = ft_add_char(tmp2, str[i]);
	*/		i++;
		}
		len = i - j;
		k = 0;
		if (!((tmp1 = malloc(sizeof(char) * (len + 1)))))
						return (0);
		while (k < len)
		{
			tmp1[k] = str[j + k];
			k++;
		}
		tmp1[k] = '\0';
		((*param)->min_width) = ft_atoi(tmp1, 'd');
	//	free(tmp1);
	}
	return (i);
}

int				check_prec_type(char *s, int i, t_struct **par)
{
//	char		*tmp1;
//	char		*tmp2;
	int			j;
	int			k;
	int			len;

	j = i;
	if (s[i] == '.')
	{
//		tmp1 = ft_strdup(".");
		i++;
		while ((ft_isdigit(s[i]) || s[i] == '*') && s[i] != '\0')
		{
//			tmp2 = ft_strdup(tmp1);
//			free(tmp1);
//			tmp1 = ft_add_char(tmp2, s[i]);
//			free(tmp2);
			i++;
		}
		len = i - j;
		if (!((*par)->prec = malloc(sizeof(char) * (len + 1))))
			return (0);
		k = 0;
		while (k < len)
		{
			(*par)->prec[k] = s[j + k];
			k++;
		}
		(*par)->prec[k] = '\0';

//		((*par)->prec) = tmp1;
//		free(tmp1);
	}
	if (ft_test_presence_char(s[i], SET_CONVERSION))
		(*par)->type = s[i];
	if (ft_test_presence_char(s[i], SET_CONVERSION))
		i++;
	if ((*par)->type == 'c' || (*par)->type == '%')
		(*par)->prec = "\0";
	return (i);
}
