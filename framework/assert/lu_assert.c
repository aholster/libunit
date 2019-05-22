/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lu_assert.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/06 17:38:44 by aholster       #+#    #+#                */
/*   Updated: 2019/05/22 13:46:26 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lu_assert.h"

void				assert(int expression, const char *format, ...)
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

static t_assertcode	assertstatus(t_assertcode code)
{
	static t_assertcode	status = 0;

	if (code != reset)
		status = testsuccess;
	return (status);
}

int					final_assert(void)
{
	t_assertcode	holder;

	holder = assertstatus(retrieve);
	assertstatus(reset);
	if (holder == testsuccess)
		return (0);
	return (-1);
}

void				softassert(int expression, const char *format, ...)
{
	va_list	ap;
	int		fd;

	fd = get_logfilefd();
	va_start(ap, format);
	if (expression == 0)
	{
		assert_format(ap, format, fd);
		assertstatus(testfail);
	}
}
