/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   assert_format.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 13:15:33 by aholster       #+#    #+#                */
/*   Updated: 2019/05/22 13:33:40 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lu_assert.h"

static size_t	ft_judex(const char *start, const int fd)
{
	size_t	judex;

	judex = 0;
	while (start[judex] != '\0' && start[judex] != '%')
	{
		judex++;
	}
	write(fd, start, judex);
	return (judex);
}

static void		lu_dispatcher(const char specifier, va_list ap, const int fd)
{
	if (specifier <= 'z' && specifier >= 'a')
	{
		if (specifier == 'c')
			lu_char(ap, fd);
		else if (specifier == 's')
			lu_str(ap, fd);
		else if (specifier == 'd')
			lu_digit(ap, fd);
		else if (specifier == 'i')
			lu_digit(ap, fd);
		else if (specifier == 'u')
			lu_unsign(ap, fd);
		else
			ft_error("invalid specifier in assert");
	}
	else
		ft_error("invalid specifier in assert");
}

/*
**		else if (specifier == 'f')
**			lu_float(ap, fd);
*/

void			assert_format(va_list ap, const char *format, const int fd)
{
	size_t	index;

	index = 0;
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			index++;
			lu_dispatcher(format[index], ap, fd);
			index++;
		}
		else
			index += ft_judex(&format[index], fd);
	}
	write(fd, "\n", 1);
}
