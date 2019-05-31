/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   assert_format.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 13:15:33 by aholster       #+#    #+#                */
/*   Updated: 2019/05/31 20:00:18 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lu_assert.h"

void			assert_format(va_list ap, const char *format, const int fd)
{
	size_t	index;

	index = 0;
	lu_putstr_fd("\n\t\t", fd);
	vdprintf(fd, format, ap);
}
