/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lu_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 17:47:26 by aholster       #+#    #+#                */
/*   Updated: 2019/05/02 17:49:15 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static void	lu_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void		lu_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2", 2);
		n = 147483648;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = (-n);
	}
	if (n > 9)
	{
		lu_putnbr_fd(n / 10, fd);
		lu_putchar_fd((n % 10) + '0', fd);
	}
	else
		lu_putchar_fd(n + '0', fd);
}
