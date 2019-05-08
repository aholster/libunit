/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lu_extractors.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/08 17:53:46 by aholster       #+#    #+#                */
/*   Updated: 2019/05/08 20:02:48 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_functions.h"

void	lu_char(va_list ap, const int fd)
{
	char	character;

	character = va_arg(ap, char);
	write(fd, &character, 1);
}

void	lu_digit(va_list ap, const int fd)
{
	long long	num;

	num = va_arg(ap, long long);
	signedll(num, fd);
}

void	lu_str(va_list ap, const int fd)
{
	char	*str;

	str = va_arg(ap, char);
	if (str == NULL)
		lu_putstr("NULL");
	else
		lu_putstr(str);
}

void	lu_unsign(va_list ap, const int fd)
{
	unsigned long long num;

	num = va_arg(ap, unsigned long long);
	unsignedll(num, fd);
}
