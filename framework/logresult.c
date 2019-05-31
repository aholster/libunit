/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   logresult.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/31 19:50:17 by aholster       #+#    #+#                */
/*   Updated: 2019/05/31 19:51:50 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static int	putbasic(t_retcode code, const int fd)
{
	if (code == ok)
	{
		lu_putstr_fd("[OK]", fd);
		return (1);
	}
	else if (code == ko)
		lu_putstr_fd("[KO]", fd);
	else if (code == segv)
		lu_putstr_fd("[SEGV]", fd);
	else if (code == buse)
		lu_putstr_fd("[BUSE]", fd);
	else if (code == timeout)
		lu_putstr_fd("[TIMEOUT]", fd);
	else if (code == unexpect)
		lu_putstr_fd("[UNEXPECTED]", fd);
	else
		ft_error("unknown return code");
	return (-1);
}

static int	expectcrash(t_retcode code, t_retcode expected, const int fd)
{
	if (code == expected)
	{
		lu_putstr_fd("[Succesfully crashed!]", fd);
		return (1);
	}
	lu_putstr_fd("Expected:", fd);
	putbasic(expected, fd);
	lu_putstr_fd("result:", fd);
	putbasic(code, fd);
	return (-1);
}

static int	expecttimeout(t_retcode code, t_retcode expected, const int fd)
{
	if (code == expected)
	{
		lu_putstr_fd("[Succesfully timed-out!]", fd);
		return (1);
	}
	lu_putstr_fd("Expected:", fd);
	putbasic(expected, fd);
	lu_putstr_fd("result:", fd);
	putbasic(code, fd);
	return (-1);
}

int			logresult(t_retcode code, t_retcode expected, const int fd)
{
	if (expected == ok)
		return (putbasic(code, fd));
	else if (expected == timeout)
		return (expecttimeout(code, expected, fd));
	return (expectcrash(code, expected, fd));
}
