/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executioner.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 18:52:48 by aholster       #+#    #+#                */
/*   Updated: 2019/04/21 20:53:04 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	executioner(int (*test)(void))
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		ft_error();
	if (pid == 0)
		exit(test());
	else
	{
		wait(&status);
		if (WIFEXITED(status) != FALSE)
			return (WEXITSTATUS(status) == 0 ? ok : ko);
		if (WIFSIGNALED(status) != FALSE)
		{
			if (WTERMSIG(status) == 10)
				return (buse);
			else if (WTERMSIG(status) == 11)
				return (segv);
		}
		return (ko);
	}
}
