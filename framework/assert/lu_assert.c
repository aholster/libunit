/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lu_assert.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/06 17:38:44 by aholster       #+#    #+#                */
/*   Updated: 2019/05/22 13:28:28 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lu_assert.h"

void			assert(int expression, const char *format, ...)
{
	va_list	ap;
	size_t	index;
	int		fd;

	fd = get_logfilefd();
	index = 0;
	va_start(ap, format);
	if (expression == 0)
	{
		assert_format(ap, format, fd);
		exit(-1);
	}
}

static int		assertstatus(int	reference)
{
	static int	status = 0;

	if (reference != unexpect)
		status = reference;
	return (status);
}

int				final_assert(void)
{
	int	holder;

	holder = assertstatus(unexpect);
	assertstatus(0);
	return(holder);
}

void			softassert(int expression, const char *format, ...)
{
	va_list	ap;
	int		fd;

	fd = get_logfilefd();
	va_start(ap, format);
	if (expression == 0)
	{
		assert_format(ap, format, fd);
		assertstatus(-1);
	}
}

