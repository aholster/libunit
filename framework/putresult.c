/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   putresult.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 14:44:53 by aholster       #+#    #+#                */
/*   Updated: 2019/05/05 21:15:26 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static int	putbasic(t_retcode code)
{
	if (code == ok)
	{
		lu_putstr("\033[0;32m[OK]\033[0;00m");
		return (1);
	}
	else if (code == ko)
		lu_putstr("\033[0;31m[KO]\033[0;00m");
	else if (code == segv)
		lu_putstr("\033[0;31m[SEGV]\033[0;00m");
	else if (code == buse)
		lu_putstr("\033[0;31m[BUSE]\033[0;00m");
	else if (code == timeout)
		lu_putstr("\033[0;33m[TIMEOUT]\033[0;00m");
	else if (code == unexpect)
		lu_putstr("\033[0;31m[UNEXPECTED]\033[0;00m");
	else
		ft_error("unknown return code");
	return (-1);
}

static int	expectcrash(t_retcode code, t_retcode expected)
{
	if (code == expected)
	{
		lu_putstr("\033[0;32m[Succesfully crashed!]\033[0;00m");
		return (1);
	}
	lu_putstr("Expected:");
	putbasic(expected);
	lu_putstr("result:");
	putbasic(code);
	return (-1);
}

static int	expecttimeout(t_retcode code, t_retcode expected)
{
	if (code == expected)
	{
		lu_putstr("\033[0;32m[Succesfully timed-out!]\033[0;00m");
		return (1);
	}
	lu_putstr("Expected:");
	putbasic(expected);
	lu_putstr("result:");
	putbasic(code);
	return (-1);
}

int			putresult(t_retcode code, t_retcode expected)
{
	if (expected == ok)
		return (putbasic(code));
	else if (expected == timeout)
		return (expecttimeout(code, expected));
	return (expectcrash(code, expected));
}
