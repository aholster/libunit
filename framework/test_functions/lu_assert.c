/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lu_assert.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/06 17:38:44 by aholster       #+#    #+#                */
/*   Updated: 2019/05/06 21:37:24 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_functions.h"

static void	ft_judex(const char *start, size_t *index, const int fd)
{
	size_t	judex;

	judex = 0;
	while (start[judex] != '\0' && start[judex] != '%')
	{
		judex++;
	}
	write(fd, start, judex);
	*index += judex;
}

void		assert(int expression, const char *format, ...)
{
	va_list	ap;
	size_t	index;
	int		fd;

	fd = 2;
	// fd to be decided, probably file?
	index = 0;
	va_start(ap, format);
	if (expression == 1)
		return ;
	while (format[index] != '\0')
	{
		if (format[index] == '%')
			(void)index;
		else
			ft_judex(&format[index], &index, fd);
		index++;
	}
}
