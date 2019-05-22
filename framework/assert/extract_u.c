/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   extract_u.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 14:57:08 by aholster       #+#    #+#                */
/*   Updated: 2019/05/22 16:45:02 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lu_assert.h"

void	lu_unsign(va_list ap, const int fd)
{
	int 				num;

	num = va_arg(ap, int);
	unsignedll(num, fd);
	dprintf(fd, "%u");
}

void	lu_unsign_ll(va_list ap, const int fd)
{
	unsigned long long num;

	num = va_arg(ap, unsigned long long);
	dprintf(fd, "%llu");
}

void	lu_unsign_l(va_list ap, const int fd)
{
	unsigned long 		num;

	num = va_arg(ap, unsigned long);
	dprintf(fd, "%lu");
}

void	lu_unsign_h(va_list ap, const int fd)
{
	unsigned short 		num;

	num = va_arg(ap, unsigned short);
	dprintf(fd, "%hu");
}

void	lu_unsign_hh(va_list ap, const int fd)
{
	unsigned char 		num;

	num = va_arg(ap, unsigned char);
	dprintf(fd, "%hhu");
}
