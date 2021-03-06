/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_struct.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 10:46:03 by phperrot          #+#    #+#             */
/*   Updated: 2020/02/01 16:38:34 by phperrot         ###   ########.fr       */
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

t_struct		*ft_sstructnew(char *content)
{
	t_struct	*elem;

	if (!(elem = malloc(sizeof(t_struct))))
		return (NULL);
	elem->flag = content;
	elem->pound_flag = 0;
	elem->min_width = 0;
	elem->prec = content;
	elem->type = content[0];
	return (elem);
}

t_dstruct		*ft_dstructnew(int content)
{
	t_dstruct	*elem;

	if (!(elem = malloc(sizeof(t_dstruct))))
		return (NULL);
	elem->marker1 = content;
	elem->marker2 = content;
	elem->len_arg = content;
	elem->pound_flag = content;
	elem->double_percent = content;
	return (elem);
}
