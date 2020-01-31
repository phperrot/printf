/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 14:13:35 by phperrot          #+#    #+#             */
/*   Updated: 2020/01/31 11:23:02 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_width_display(char *preci_str, t_struct *p, int i)
{
	if (preci_str[0] == '\0' && p->type == 'c')
		i++;
	if (ft_strchr(p->flag, '-'))
	{
		if (preci_str[0] == '\0' && p->type == 'c')
			ft_putchar('\0');
		ft_putstr(preci_str);
	}
	if ((p->min_width - ft_strlen(preci_str)) > 0)
		while (i < (p->min_width - (int)ft_strlen(preci_str)))
		{
			if (ft_strchr(p->flag, '0') && !ft_strchr(
			p->flag, '-' && (ft_strlen(p->prec) == 0 ||\
			p->prec[1] == '-')))
				ft_putchar('0');
			else
				ft_putchar(' ');
			i++;
		}
	if (!ft_strchr(p->flag, '-'))
	{
		if (preci_str[0] == '\0' && p->type == 'c')
			ft_putchar('\0');
		ft_putstr(preci_str);
	}
}

void		ft_width(char *precision_str, t_struct *p)
{
	int		i;
	char	*tmp;
	int 	tmp1;
/*	ft_putstr("\n#######################\n");
	ft_putstr("FLAG=");ft_putstr(p->flag);ft_putchar('\n');
	ft_putstr("WIDTH=");ft_putnbr(p->min_width);ft_putchar('\n');
	ft_putstr("PREC=");ft_putstr(p->prec);ft_putchar('\n');	
	ft_putstr("TYPE=");ft_putchar(p->type);ft_putchar('\n');	
	ft_putstr("POUND_FLAG=");ft_putnbr(p->pound_flag);ft_putchar('\n');	
ft_putstr("LEN PRECISION STR");ft_putnbr(ft_strlen(precision_str));ft_putchar('\n');
	ft_putstr("PRECISION STR=");ft_putstr(precision_str);ft_putchar('\n');	
*/	
if ((int)ft_strlen(precision_str) >= p->min_width)
	{
		if (precision_str[0] == '\0' && p->type == 'c')
			ft_putchar('\0');
		ft_putstr(precision_str);
	}
	else
	{
		i = 0;
		tmp1 = 0;
		if (ft_strlen(p->prec) >= 1)
			tmp1 = (ft_atoi(p->prec + 1, 'd') < 0)? 1 : 0;
		if (precision_str[0] == '-' && ft_strchr(p->flag, '0')
//		&& !ft_strchr(p->flag, '-') && (ft_atoi(p->prec + 1, 'd') < 0
		&& !ft_strchr(p->flag, '-') && ( tmp1
		|| ft_strlen(p->prec) == 0))
		{
			ft_putchar('-');
			tmp = ft_strdup(precision_str);
			precision_str = ft_strdup(tmp + 1);
			free(tmp);
			i++;
		}
//		else 
//			precision_str = ft_strdup("");
//	ft_putchar('-');	ft_putstr(precision_str);ft_putchar('-');
		ft_width_display(precision_str, p, i);
	}
}
