/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:38:24 by phperrot          #+#    #+#             */
/*   Updated: 2020/01/30 19:09:36 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf_number_args(const char *str)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '%' && str[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

char			*ft_get_arg(va_list arguments, t_struct **param)
{
	void		*output;

	if (((*param)->pound_flag)  || (ft_strchr((*param)->prec, '*') > 0))
	{
	ft_putstr("\n888888888888888888888888888\n");
	ft_putstr("888888888888888888888888888\n");
	ft_putstr("888888888888888888888888888\n");
	ft_putstr("888888888888888888888888888\n");
	ft_putstr("FLAG:"); ft_putnbr((*param)->pound_flag);ft_putchar('\n');
	ft_putstr("PREC:"); ft_putstr((*param)->prec);ft_putchar('\n');
	ft_putstr("type:"); ft_putchar((*param)->type);ft_putchar('\n');
	output = ft_itoa((int)va_arg(arguments, int));
	ft_putstr("OUTPUT:"); ft_putstr(output);ft_putchar('\n');
		return (output);
	}
	if ((*param)->type == 's')
		output = ft_strdup(va_arg(arguments, char*));
	if ((*param)->type == 'c')
		output = ft_ctoa((char)va_arg(arguments, int));
	if ((*param)->type == 'p')
		output = ft_itoa(((unsigned long)\
		va_arg(arguments, unsigned long)));
	if (ft_strchr("di*", (*param)->type) != 0)
		output = ft_itoa((int)va_arg(arguments, int));
	if (ft_strchr("uXxo", (*param)->type) != 0)
		output = ft_itoa((unsigned int)va_arg(arguments, unsigned int));
	if ((*param)->type == '%')
		output = ft_ctoa('%');
	if ((*param)->type == '%')
		(*param)->type = 'c';
	if (output == NULL)
		output = ft_strdup("(null)");
	ft_putstr("\n888888888888888888888888888\n");
	ft_putstr("OUTPUT:");ft_putstr(output);ft_putchar('\n');
	return (output);
}

int				ft_no_arg(const char *s)
{
	int			count;
	int			i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] == '%')
			i++;
		ft_putchar(s[i]);
		count++;
		i++;
	}
	return (count);
}

int				ft_printf(const char *s, ...)
{
	va_list		arguments;
	int			count;
	t_dstruct	*result;
	int			i;
	int			tmp;

	i = 0;
	count = (ft_printf_number_args(s) == 0) ? ft_no_arg(s) : 0;
	va_start(arguments, s);
	if (ft_printf_number_args(s) == 0)
		return (count);
	tmp = 0;
	while (i <= ft_printf_number_args(s) || tmp < (int)ft_strlen(s))
	{
		result = ft_read_string((char*)s, arguments, tmp);
		count = count + (result->len_arg) + result->marker1;
		tmp = result->marker2;
		i++;
		free(result);
	}
	va_end(arguments);
	return (count);
}
