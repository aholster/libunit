/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   extractors.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/08 17:53:46 by aholster       #+#    #+#                */
/*   Updated: 2019/05/22 18:14:39 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lu_assert.h"

void	lu_char(va_list ap, const int fd)
{
	int	character;

	character = (int)va_arg(ap, int);
	lu_putcaret_fd(character, fd);
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

void	lu_mem(va_list ap, const int fd)
{
	char	*mem;
	size_t	size;

	size = va_arg(ap, size_t);
	mem = va_arg(ap, char *);
	if (mem == NULL)
		lu_putstr_fd("NULL", fd);
	else
		write(fd, mem, size);
}
