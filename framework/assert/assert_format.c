/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   assert_format.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 13:15:33 by aholster       #+#    #+#                */
/*   Updated: 2019/05/22 16:53:31 by aholster      ########   odam.nl         */
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

static int		verifynum(const char *specifier)
{
	char	first;

	first = *specifier;
	if (first == 'h' || first == 'l')
	{
		if (*specifier + 1 == 'd' || *specifier + 1 == 'u'\
			|| *specifier + 1 == 'i')
			return (0);
		if (first == *specifier + 1)
		{
			if (*specifier + 2 == 'd' || *specifier + 2 == 'u'\
				|| *specifier + 2 == 'i')
				return (0);
		}
	}
	return (-1);
}

static void		activatenum(const char *specifier, va_list ap, const int fd)
{
	if (*specifier == 'h')
	{
		if (*specifier + 1 == 'd')
			lu_digit_h(ap, fd);
		else if (*specifier + 1 == 'u')
			lu_unsign_h(ap, fd);
		else if (*specifier + 2 == 'd')
			lu_unsign_hh(ap, fd);
		else
			lu_digit_hh(ap, fd);
	}
	else if (*specifier == 'l')
	{
		if (*specifier + 1 == 'd')
			lu_digit_l(ap, fd);
		else if (*specifier + 1 == 'u')
			lu_unsign_l(ap, fd);
		else if (*specifier + 2 == 'd')
			lu_digit_ll(ap, fd);
		else
			lu_unsign_ll(ap, fd);
	}
}

static void		dispatcher(const char *specifier, va_list ap, const int fd)
{
	if (*specifier <= 'z' && *specifier >= 'a')
	{
		if (*specifier == 'c')
			lu_char(ap, fd);
		else if (*specifier == 's')
			lu_str(ap, fd);
		else if (*specifier == 'm')
			lu_mem(ap, fd);
		else if (*specifier == 'd' || *specifier == 'i')
			lu_digit(ap, fd);
		else if (*specifier == 'u')
			lu_unsign(ap, fd);
		else if (verifynum(specifier) == 0)
			activatenum(specifier, ap, fd);
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
			dispatcher(format + index, ap, fd);
			index++;
		}
		else
			index += ft_judex(&format[index], fd);
	}
	write(fd, "\n", 1);
}
