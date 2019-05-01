/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_error.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 17:47:11 by aholster       #+#    #+#                */
/*   Updated: 2019/05/01 15:47:54 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static void		lu_putstrerr(char const *s)
{
	write(2, s, lu_strlen(s));
}

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

static void		lu_puterror(char *format, char *str)
{
	size_t	index;

	index = subfinder(format);
	if (format[index] == '%')
	{
		write(2, format, index);
		lu_putstrerr(str);
		lu_putstrerr(&format[index + 1]);
	}
	else
	{
		lu_putstrerr(format);
	}
}

void			ft_error(char *error)
{
	lu_puterror("ERRROR:\033[0;33m%\033[0;00m\n", error);
	exit(-1);
}
