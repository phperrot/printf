/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_read_param.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 09:10:57 by phperrot          #+#    #+#             */
/*   Updated: 2020/02/01 16:35:50 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct		*ft_parsing(int *i, char **tmp, char **tmp1, char *str)
{
	t_struct	*par;
	int			incrementor;

	incrementor = 0;
	par = ft_sstructnew("\0");
	*i = *i + 1;
	*i = check_flag(str, *i, &par, incrementor);
	*tmp = ft_strdup(par->flag);
	*i = check_width(str, *i, &par);
	*i = check_prec_type(str, *i, &par, incrementor);
	*tmp1 = ft_strdup(par->prec);
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
	}
	return (arg);
}

void			ft_star(t_struct **par, char **arg, char **tmp1, va_list l)
{
	(**par).prec = ft_strdup_free((**par).prec, *arg);
	*arg = ft_strjoin_free(".", *arg, 2);
	*tmp1 = ft_strdup_free(*tmp1, *arg);
	free(*arg);
	(**par).pound_flag = 0;
	*arg = ft_get_arg(l, &(*par));
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
		ft_star(&(par), &arg, &tmp1, l);
	if (ft_strlen(arg) >= 2 && ft_strlen(tmp1) >= 2)
		if (tmp1[1] == '-' && arg[0] == '0' && arg[1] == '\0')
			tmp1 = ft_strdup_free(tmp1, "");
	if (ft_strlen(par->flag))
		free(par->flag);
	par->flag = ft_strdup_free(tmp, tmp);
	if (ft_strlen(par->prec))
		free(par->prec);
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
		if (str[i] == '%' && str[i + 1] != '%' && str[i + 1] != '\0')
		{
			result->marker1 = i - k;
			i = ft_param(i, str, arguments, &result);
			result->marker2 = i;
			return (result);
		}
		if (str[i] != '%')
			ft_putchar(str[i]);
		i++;
	}
	result->marker1 = i - k - result->double_percent;
	result->marker2 = i;
	return (result);
}
