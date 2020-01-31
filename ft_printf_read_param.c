/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_read_param.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 09:10:57 by phperrot          #+#    #+#             */
/*   Updated: 2020/01/31 10:43:11 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			multi_free(char *s1, char *s2, char *s3, t_struct *struct1)
{
	free(s1);
	free(s2);
	free(s3);
	free(struct1);
}

t_struct		*ft_parsing(int *i, char **tmp, char **tmp1, char *str)
{
	t_struct	*par;

	par = ft_sstructnew("\0");
	*i = *i + 1;
	*i = check_flag(str, *i, &par);
	*tmp = ft_strdup(par->flag);
	*i = check_width(str, *i, &par);
	*i = check_prec_type(str, *i, &par);
	*tmp1 = ft_strdup(par->prec);
/*	ft_putstr("\n==============\n");
	ft_putstr("FLAG=");ft_putstr(par->flag);ft_putchar('\n');
	ft_putstr("WIDTH=");ft_putnbr(par->min_width);ft_putchar('\n');
	ft_putstr("PREC=");ft_putstr(par->prec);ft_putchar('\n');
*///	if ((par->prec))
//		free(par->prec);
	return (par);
}

char			*ft_wildcard(t_struct **p, char *arg, char **tmp, va_list args)
{
	if ((*p)->pound_flag == 1)
	{
		(*p)->min_width = ft_atoi(arg, 'd');
		if (ft_atoi(arg, 'd') < 0)
		{
			(*p)->min_width = -((*p)->min_width);
			*tmp = ft_strreplace(*tmp, '0', 'e');
			*tmp = ft_strjoin_free("--", *tmp, 2);
		}
		(*p)->pound_flag = 0;
		free(arg);
		arg = ft_get_arg(args, &(*p));
//		free((*p)->prec);
	}
	return (arg);
}

int				ft_param(int i, char *s, va_list l, t_dstruct **r)
{
	char		*arg;
	char		*tmp;
	char		*tmp1;
	t_struct	*par;

	par = ft_parsing(&i, &tmp, &tmp1, s);
	arg = ft_get_arg(l, &(par));
	arg = ft_wildcard(&par, arg, &tmp, l);
	if (ft_strncmp(par->prec, ".*", 2) == 0)
	{
/**/	(*par).prec = ft_strdup(arg);
//		ft_putstr(par->prec);ft_putchar('\n');ft_strchr(par->prec, '*');
//		ft_putstr("\nvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv  ");ft_putnbr(i);ft_putchar('\n');
//		ft_putstr(arg);ft_putchar('\n');
		arg = ft_strjoin_free(".", arg, 2);
//		ft_putstr(arg);ft_putchar('\n');
		tmp1 = ft_strdup_free(tmp1, arg);
		free(arg);
		(*par).pound_flag = 0;
		arg = ft_get_arg(l, &(par));
//		ft_putstr("\nooooooooooooooooooooooooooooooooooo\n");
//		ft_putstr(arg);ft_putchar('\n');
//		ft_putstr("TYPE");ft_putchar((par)->type);ft_putchar('\n');
/*
 * NEW
*/ //		par->prec = arg;
	}
	if (ft_strlen(arg) >= 2 && ft_strlen(tmp1) >= 2)
	if (tmp1[1] == '-' && arg[0] == '0' && arg[1] == '\0')
		tmp1 = ft_strdup_free(tmp1, "");
	par->flag = ft_strdup_free(tmp, tmp);
	par->prec = ft_strdup_free(tmp1, tmp1);
	(*r)->len_arg = ft_display(par, arg) - (*r)->double_percent;
	if (arg[0] == 0 && par->type == 'c' && par->min_width < 1)
		(*r)->len_arg++;
	multi_free(arg, par->flag, par->prec, par);
	return (i);
}

/*
**decomposition of %[flag][min width][precision][length modifier][argumenttype]
*/

t_dstruct		*ft_read_string(char *str, va_list arguments, int i)
{
	int			k;
	t_dstruct	*result;

	result = ft_dstructnew(0);
	k = i;
	while (str[i] != '\0')
	{
		result->double_percent = result->double_percent +\
		check_double_percent(str, &i);
		if (str[i] == '%' && str[i + 1] != '%')
		{
			result->marker1 = i - k;
			i = ft_param(i, str, arguments, &result);
			result->marker2 = i;
			return (result);
		}
		ft_putchar(str[i]);
		i++;
	}
	result->marker1 = i - k - result->double_percent;
	result->marker2 = i;
	return (result);
}
