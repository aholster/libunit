/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executioner.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 18:52:48 by aholster       #+#    #+#                */
/*   Updated: 2019/04/29 18:07:20 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static int				dreamer(void)
{
	sleep(TIMEOUT - 5);
	lu_putstr("	5...");
	sleep(1);
	lu_putstr("\033[5D	4...");
	sleep(1);
	lu_putstr("\033[5D	3...");
	sleep(1);
	lu_putstr("\033[5D	2...");
	sleep(1);
	lu_putstr("\033[5D	1...");
	sleep(1);
	exit(0);
}

static enum e_retcode	retcode(int status)
{
	int	signaltype;

	if (WIFEXITED(status) != FALSE)
		return (WEXITSTATUS(status) == 0 ? ok : ko);
	if (WIFSIGNALED(status) != FALSE)
	{
		signaltype = WTERMSIG(status);
		if (signaltype == 10)
			return (buse);
		else if (signaltype == 11)
			return (segv);
	}
	return (unexpect);
}

static enum e_retcode	resolver(pid_t timer_pid, pid_t test_pid)
{
	pid_t			first;
	int				status;
	enum e_retcode	ret;

	ret = unexpect;
	first = waitpid(WAIT_ANY, &status, 0);
	if (first == test_pid)
	{
		kill(timer_pid, SIGKILL);
		ret = retcode(status);
	}
	else if (first == timer_pid)
	{
		kill(test_pid, SIGKILL);
		ret = timeout;
	}
	first = waitpid(WAIT_ANY, &status, 0);
	return (ret);
}

enum e_retcode			executioner(int (*test)(void))
{
	pid_t	timer_pid;
	pid_t	test_pid;

	timer_pid = fork();
	if (timer_pid < 0)
		ft_error("fork failure");
	if (timer_pid == 0)
		dreamer();
	test_pid = fork();
	if (test_pid < 0)
		ft_error("fork failure");
	if (test_pid == 0)
		exit(test());
	else
	{
		return (resolver(timer_pid, test_pid));
	}
}
