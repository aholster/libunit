/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lu_extractors.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/08 17:53:46 by aholster       #+#    #+#                */
/*   Updated: 2019/05/21 19:30:34 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_functions.h"

void	lu_char(va_list ap, const int fd)
{
	char	character;

	character = (char)va_arg(ap, int);
	if (character == '\0')
		write(fd, "\\0", 2);
	else if (character == '\n')
		write(fd, "\\n", 2);
	else
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

	str = va_arg(ap, char *);
	if (str == NULL)
		lu_putstr_fd("NULL", fd);
	else
		lu_putstr_fd(str, fd);
}

void	lu_unsign(va_list ap, const int fd)
{
	unsigned long long num;

	num = va_arg(ap, unsigned long long);
	unsignedll(num, fd);
}
