/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 10:57:23 by phperrot          #+#    #+#             */
/*   Updated: 2020/01/30 19:07:22 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int a;
	int	b;

	a = ft_printf("+%.*s", 3, "hello");
	b = printf("-%.*s", 3, "hello");
	ft_putchar('\n');
	printf("\nA=%d\nB=%d\n", a, b);
//	system("leaks a.out");
}
