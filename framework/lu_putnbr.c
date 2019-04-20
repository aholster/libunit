/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lu_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:18:57 by aholster       #+#    #+#                */
/*   Updated: 2019/04/20 20:57:34 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static void	lu_putchar(char c)
{
	write(1, &c, 1);
}

void		lu_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2", 2);
		n = 147483648;
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		n = (-n);
	}
	if (n > 9)
	{
		lu_putnbr(n / 10);
		lu_putchar((n % 10) + '0');
	}
	else
		lu_putchar(n + '0');
}
