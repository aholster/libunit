/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lu_longprint.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/08 20:00:03 by aholster       #+#    #+#                */
/*   Updated: 2019/05/08 20:43:09 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_functions.h"

static unsigned short	longlen(long long n)
{
	unsigned short length;

	length = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		length++;
	while (n != 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

void					signedll(long long num, const int fd)
{
	unsigned short	len;
	unsigned short	curlen;
	char			buf[20];

	if (num == -9223372036854775807LL)
		lu_putstr_fd("-9223372036854775807", fd);
	else
	{
		len = longlen(num) - 1;
		if (num < 0)
		{
			buf[0] = '-';
			num = (-num);
		}
		curlen = len;
		while (num > 9)
		{
			buf[curlen] = (num % 10) + '0';
			num /= 10;
			curlen--;
		}
		buf[curlen] = (num + '0');
		write(fd, buf, len + 1);
	}
}

/*
**	possibly wrong value for max negative long long
*/

void					unsignedll(unsigned long long num, const int fd)
{
	unsigned short	len;
	unsigned short	curlen;
	char			buf[20];

	len = longlen(num) - 1;
	curlen = len;
	while (num > 9)
	{
		buf[curlen] = (num % 10) + '0';
		num /= 10;
		curlen--;
	}
	buf[curlen] = (num + '0');
	write(fd, buf, len + 1);
}
