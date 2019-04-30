/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lu_putstrstr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 13:59:40 by aholster       #+#    #+#                */
/*   Updated: 2019/04/30 19:48:46 by aholster      ########   odam.nl         */
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

void			lu_putstrstr(char *format, char *str)
{
	size_t	index;

	index = subfinder(format);
	if (format[index] == '%')
	{
		write(1, format, index);
		lu_putstr(str);
		lu_putstr(&format[index + 1]);
	}
	else
	{
		lu_putstr(format);
	}
}
