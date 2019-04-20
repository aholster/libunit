/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executioner.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 18:52:48 by aholster       #+#    #+#                */
/*   Updated: 2019/04/20 20:44:52 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

#include <stdio.h>
int	executioner(int	(*test)(void))
{
	pid_t	pid;
	int		status;

//	if (test == NULL)
//		return (ko);
	pid = fork();
	if (pid < 0)
		ft_error();
	if (pid == 0)
		exit (test());
	else
	{
		wait(&status);
		if (WIFEXITED(status) != FALSE)
			return (WEXITSTATUS(status) == 0 ? ok : ko);
		if (WIFSIGNALED(status) != FALSE)
		{
			return (segv);
		}
		return (ko);
	}
}

// int	crash(void)
// {
// 	char *str;
// 	unsigned int big;

// 	big = 100;
// 	str = NULL;
// 	while (1)
// 	{
// 		str[big] = '\0';
// 		big++;
// 	}
// }

// int	main(void)
// {
// 	printf("%d\n", executioner(&crash));
// 	return (1);
// }