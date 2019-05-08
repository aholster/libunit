/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lu_assert.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/06 17:38:44 by aholster       #+#    #+#                */
/*   Updated: 2019/05/08 17:48:17 by aholster      ########   odam.nl         */
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
//	*index += judex;
	return (judex);
}

static void		lu_dispatcher(t_wrtfunc *dispatch, const char specifier,\
				va_list ap, const int fd)
{
	if (specifier <= 'z' && specifier >= 'a')
	{
		if ((dispatch)[specifier - 'a'] != NULL)
			((dispatch)[specifier - 'a'])(ap, fd);
		else
			ft_error("invalid specifier in dispatcher");
	}
	else
		ft_error("invalid specifier in dispatcher");
}

/*
**	a	b	c	d	e	f	g	h	i	j	k	l	m	n	o	p	q	r	s	t	u	v	w	x	y	z
**	N	N			N		N	N		N	N	N	N	N	N	N	N	N		N	N	N	N	N	N	
*/

void			assert(int expression, const char *format, ...)
{
	static const t_wrtfunc	dispatch[26] = {NULL, NULL, lu_char, lu_digit, NULL,\
	NULL /*lu_float*/, NULL, NULL, lu_digit, NULL, NULL, NULL, NULL, NULL, NULL, NULL,\
	NULL, NULL, lu_str, NULL, NULL, NULL, NULL, NULL, NULL, lu_unsign};
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
		{
			index++;
			lu_dispatcher(dispatch, format[index], ap, fd);
			index++;
		}
		else
			index += ft_judex(&format[index], fd);
	}
}
