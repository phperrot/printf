/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 10:57:23 by phperrot          #+#    #+#             */
/*   Updated: 2020/01/31 11:42:19 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int a;
	int	b;

	a = 0;
	b = 0;
	a = ft_printf("%.3d", 3);
	b = printf("%.3d", 3);
//	a = ft_printf("+%0.s %-d %.*s %c %5d %0.i %3%  === %x", "salut", 4, 3, "hello", '@', 5, 3, 192);
//	b = printf("+%.*s %c %5d %0.i %3%  === %x", 3, "hello", '@', 5, 3, 192);
	ft_putchar('\n');
	printf("\nA=%d\nB=%d\n", a, b);
//	system("leaks a.out");
}
