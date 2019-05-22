/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   extract_d.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 14:57:10 by aholster       #+#    #+#                */
/*   Updated: 2019/05/22 17:32:16 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lu_assert.h"

void	lu_digit(va_list ap, const int fd)
{
	int			num;

	num = va_arg(ap, int);
	dprintf(fd, "%d", num);
}

void	lu_digit_ll(va_list ap, const int fd)
{
	long long	num;

	num = va_arg(ap, long long);
	dprintf(fd, "%lld", num);
}

void	lu_digit_l(va_list ap, const int fd)
{
	long		num;

	num = va_arg(ap, long);
	dprintf(fd, "%ld", num);
}

void	lu_digit_h(va_list ap, const int fd)
{
	short		num;

	num = (short)va_arg(ap, int);
	dprintf(fd, "%hd", num);
}

void	lu_digit_hh(va_list ap, const int fd)
{
	char		num;

	num = (char)va_arg(ap, int);
	dprintf(fd, "%hhd", num);
}
