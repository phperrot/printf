/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parameters.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:29:36 by phperrot          #+#    #+#             */
/*   Updated: 2020/02/01 15:16:25 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_test_presence_char(char c, char *set)
{
	int		j;

	j = 0;
	while (set[j] != '\0')
	{
		if (set[j] == c)
			return (1);
		j++;
	}
	return (0);
}

char		*ft_add_char(char *str, char c)
{
	int		size;
	char	*output;
	int		i;

	size = 0;
	if (str && str != NULL)
	{
		while (str[size] != '\0')
			size++;
	}
	if (!(output = malloc(sizeof(char) * (size + 2))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		output[i] = str[i];
		i++;
	}
	output[size] = c;
	output[size + 1] = '\0';
	return (output);
}

int			ft_display(t_struct *param, char *argv)
{
	char	*str;
	int		size;
	int		width;
//	char	*tmp;
//	ft_putstr("\nmmmmmmmmmmmmmmmmmmmmmm\n");
//	ft_putstr("ARGV:");ft_putstr(argv);ft_putchar('\n');

	str = ft_precision(argv, param);
	if (ft_strchr(param->flag, '#') != 0)
	{
		if (param->type == 'o')
			str = ft_strjoin_free("0", str, 2);
		if (param->type == 'x' || param->type == 'X')
			str = ft_strjoin_free("0x", str, 2);
	}
	if (param->type == 'p')
		str = ft_strjoin_free("0x", str, 2);

	//size = (int)ft_strlen(str);

//	tmp = ft_strdup(str);
	ft_width(&str, param);
//	ft_width(str, param);
	size = (int)ft_strlen(str);
	free(str);
//	free(tmp);
	width = param->min_width;
	if (param->min_width > size)
		return (param->min_width);
	else
		return (size);
}
