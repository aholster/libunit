/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executioner.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 18:52:48 by aholster       #+#    #+#                */
/*   Updated: 2019/05/06 15:50:12 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static int			dreamer(void)
{
	if (TIMEOUT <= 5)
	{
		sleep(TIMEOUT);
		exit(0);
	}
	sleep(TIMEOUT - 5);
	lu_putstr(" \033[0;33m5...\033[5D\033[0;00m");
	sleep(1);
	lu_putstr(" \033[0;33m4...\033[5D\033[0;00m");
	sleep(1);
	lu_putstr(" \033[0;33m3...\033[5D\033[0;00m");
	sleep(1);
	lu_putstr(" \033[0;33m2...\033[5D\033[0;00m");
	sleep(1);
	lu_putstr(" \033[0;33m1...\033[5D\033[0;00m");
	sleep(1);
	exit(0);
}

static t_retcode	retcode(int status)
{
	int	signaltype;

	if (WIFEXITED(status) != FALSE)
		return (WEXITSTATUS(status) == 0 ? ok : ko);
	if (WIFSIGNALED(status) != FALSE)
	{
		signaltype = WTERMSIG(status);
		if (signaltype == SIGBUS)
			return (buse);
		else if (signaltype == SIGSEGV)
			return (segv);
	}
	return (unexpect);
}

static t_retcode	resolver(pid_t timer_pid, pid_t test_pid)
{
	pid_t			first;
	int				status;
	t_retcode		ret;

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

t_retcode			executioner(int (*test)(void))
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
