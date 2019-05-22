/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   extract_d.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 14:57:10 by aholster       #+#    #+#                */
/*   Updated: 2019/05/22 16:45:43 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lu_assert.h"

void	lu_digit(va_list ap, const int fd)
{
	int			num;

	num = va_arg(ap, int);
	dprintf(fd, "%d");
}

void	lu_digit_ll(va_list ap, const int fd)
{
	long long	num;

	num = va_arg(ap, long long);
	dprintf(fd, "%lld");
}

void	lu_digit_l(va_list ap, const int fd)
{
	long 		num;

	num = va_arg(ap, long);
	dprintf(fd, "%ld");
}

void	lu_digit_h(va_list ap, const int fd)
{
	short		num;

	num = va_arg(ap, short);
	dprintf(fd, "%hd");
}

void	lu_digit_hh(va_list ap, const int fd)
{
	char		num;

	num = va_arg(ap, char);
	dprintf(fd, "%hhd");
}
