/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:16:36 by phperrot          #+#    #+#             */
/*   Updated: 2020/01/31 11:43:42 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char		*ft_prec_pars(char *argv, char type, t_struct **param, int *neg)
{
	long	arg;
	char	*output;
	char	*tmp;

//	ft_putstr("\n**********************\n");
//	ft_putstr("ARGV ");ft_putstr(argv);ft_putchar('\n');
	
	if ((ft_test_presence_char((*param)->type, SET_CHAR)))
		output = ft_strdup(argv);
	else
	{
		arg = ft_atoi(argv, type);
		if (arg < 0 && ft_strchr("pxXu", type) == 0)
		{
			arg = -arg;
			*neg = 1;
		}
		tmp = ft_itoa(arg);
//		ft_putstr("\n**********************\n");
//		ft_putnbr(arg);ft_putchar('\n');
//	ft_putstr("LEN PRECISION TMP");ft_putstr((tmp));ft_putchar('\n');

		if (!(output = malloc(sizeof(char) * (1))))
			return (NULL);
	/*	int i;
		i = 0;
		while (i < (int)ft_strlen(tmp))
		{
		//	output[i] = '0';
			i++;
		}
		output[i] = '\0';
	*/	output[0] = '\0';
		free(tmp);
		convbase(arg, *param, 0, &output);
	}
//		ft_putstr("\n||||||||||||||||||||||||||||\n");
//		ft_putstr("LEN PRECISION STR--");ft_putstr((output));ft_putchar('\n');
	return (output);
}

char		*ft_prec_fin(t_struct *param, char *output, int preci, int neg)
{
	int		i;
	char	*str;
	int		size;
//	int		j;

	i = neg;
//	if (!(str = malloc(sizeof(char) * (preci + 1 + neg))))
//		return (NULL);
	if (param->type == 's')
		str = ft_strdup("");
	else
	{
	if (!(str = malloc(sizeof(char) * (preci + 1 + neg))))
		return (NULL);
	}	
	//	j = 0;
/*	ft_putstr("preci:");ft_putnbr(preci);ft_putchar('\n');
	ft_putstr("neg:");ft_putnbr(neg);ft_putchar('\n');
	while (j < preci + neg)
	{
		str[j] = '0';
		j++;
	}
	str[j] = '\0';
*/	if (neg && ft_strchr("Xxu", param-> type) == 0)
		str[0] = '-';
	if (param->type == 's')
		str = ft_strjoin_free(str, output, 3);
	if (param->type == 's')
		return (str);
	size = ft_strlen(output);
	while (i < preci + neg)
	{
		if (i < preci - size + neg)
			str[i] = '0';
		else
			str[i] = output[size - preci + i - neg];
		i++;
	}
	str[i] = '\0';
	free(output);
	return (str);
}

char		*ft_precision(char *argv, t_struct *p)
{
	char	*output;
	int		negative;
	char	*str;
	int		prec;

	negative = 0;
	if (ft_strlen(p->prec) >= 1)
	{
	if (ft_atoi(p->prec + 1, 'd') < 0 && p->type == 's')
		return (ft_strdup(argv));
	if (ft_atoi(argv, 'd') == 0 && p->type != 's' && ft_strlen(p->
				prec) > 0 && ft_atoi(p->prec + 1, 'd') == 0)
		return (ft_strdup(""));
	}
	if (ft_strlen(p->prec) >= 1)
		prec = (ft_atoi(p->prec + 1, 'd') < 0) ? 0 : ft_atoi(p->prec + 1, 'd');
	output = ft_prec_pars(argv, (p)->type, &p, &negative);
	if (ft_strlen(p->prec) <= 1 || ((ft_strlen(p->prec) == 2)
		&& p->prec[1] == '0') || (prec < (int)ft_strlen(output)))
	{
//	ft_putstr("\n>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
//	ft_putstr("LEN PRECISION STR--");ft_putstr((output));ft_putchar('\n');
		if (p->type == 's' && prec <
				(int)ft_strlen(output) && ft_strchr(p->prec, '.'))
			output[prec] = '\0';
		if (ft_atoi(argv, 'd') < 0 && ft_strchr("id", p->type) > 0)
			output = ft_strjoin_free("-", output, 2);
		return (output);
	}
	str = ft_prec_fin(p, output, prec, negative);
//	ft_putstr("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@22\n");
//	ft_putstr("LEN PRECISION STR");ft_putnbr(ft_strlen(str));ft_putchar('\n');
	return (str);
}
