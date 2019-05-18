/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lu_assert.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/06 17:38:44 by aholster       #+#    #+#                */
/*   Updated: 2019/05/18 16:42:35 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_functions.h"

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

/*
**		else if (specifier == 'f')
**			lu_float(ap, fd);
*/

static void		lu_dispatcher(const char specifier, va_list ap, const int fd)
{
	if (specifier <= 'z' && specifier >= 'a')
	{
		if (specifier == 'c')
			lu_char(ap, fd);
		else if (specifier == 'd')
			lu_digit(ap, fd);
		else if (specifier == 'i')
			lu_digit(ap, fd);
		else if (specifier == 's')
			lu_str(ap, fd);
		else if (specifier == 'z')
			lu_unsign(ap, fd);
		else
			ft_error("invalid specifier in dispatcher");
	}
	else
		ft_error("invalid specifier in dispatcher");
}

void			assert(int expression, const char *format, ...)
{
	va_list	ap;
	size_t	index;
	int		fd;

	fd = 2;
	// fd to be decided, probably file?
	index = 0;
	va_start(ap, format);
	if (expression == 0)
	{
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
		exit(-1);
	}
}
