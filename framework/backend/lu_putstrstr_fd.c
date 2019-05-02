/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lu_putstrstr_fd.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 17:45:56 by aholster       #+#    #+#                */
/*   Updated: 2019/05/02 17:48:55 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static size_t	subfinder(char *format)
{
	size_t	index;

	index = 0;
	while (format[index] != '\0' && format[index] != '%')
	{
		index++;
	}
	return (index);
}

void			lu_putstrstr_fd(char *format, char *str, int fd)
{
	size_t	index;

	index = subfinder(format);
	if (format[index] == '%')
	{
		write(fd, format, index);
		lu_putstr_fd(str, fd);
		lu_putstr_fd(&format[index + 1], fd);
	}
	else
	{
		lu_putstr_fd(format, fd);
	}
}
