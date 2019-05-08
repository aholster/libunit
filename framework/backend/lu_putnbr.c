/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lu_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:18:57 by aholster       #+#    #+#                */
/*   Updated: 2019/05/08 18:49:02 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	lu_putnbr(int n)
{
	char	buf[11];
	size_t	curlen;
	size_t	len;

	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		curlen = ft_nbrlen(n, 10) - 1;
		if (n < 0)
		{
			buf[0] = '-';
			n = (-n);
		}
		len = curlen;
		while (n > 9)
		{
			buf[curlen] = (n % 10) + '0';
			n /= 10;
			curlen--;
		}
		buf[curlen] = (n + '0');
		write(1, buf, len + 1);
	}
}
