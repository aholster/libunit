/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lu_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:18:57 by aholster       #+#    #+#                */
/*   Updated: 2019/05/08 20:21:40 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static unsigned int	lu_nbrlen(long long n, unsigned int base)
{
	unsigned int length;

	length = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		length++;
	while (n != 0)
	{
		n = n / base;
		length++;
	}
	return (length);
}

void				lu_putnbr(int n)
{
	char	buf[11];
	size_t	curlen;
	size_t	len;

	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		curlen = lu_nbrlen(n, 10) - 1;
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
