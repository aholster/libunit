/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lu_assert.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/06 17:38:44 by aholster       #+#    #+#                */
/*   Updated: 2019/05/22 21:44:42 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lu_assert.h"

void	assert(int expression, const char *format, ...)
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

int		assert_status(t_assertcode code)
{
	static t_assertcode	status = testsuccess;
	t_assertcode		holder;

	holder = status;
	if (code == retrieve)
		status = testsuccess;
	else if (code == testfail)
		status = testfail;
	return (holder);
}

void	softassert(int expression, const char *format, ...)
{
	va_list	ap;
	int		fd;

	fd = get_logfilefd();
	va_start(ap, format);
	if (expression == 0)
	{
		assert_format(ap, format, fd);
		assert_status(testfail);
	}
}
