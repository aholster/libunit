/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   02_writing_test.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 16:54:19 by aholster       #+#    #+#                */
/*   Updated: 2019/05/03 16:29:23 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdio.h>
int	basic_writing(void)
{
	char	*output;
	char	*input;
	size_t	readsize;
	ssize_t	status;
	int		pipes[2];

	readsize = 14;
	input = "one";

	if (pipe(pipes) == -1)
		ft_error("pipes failure");
	if (close(1) == -1)
		ft_error("failed to close stdin");
	if (dup2(pipes[1], 1) == -1)
		ft_error("failed to reroute fd");
	
	lu_putstr(input);

	output = (char *)malloc(sizeof(char) * readsize + 1);
	if (output == NULL)
		ft_error("malloc failed");
	status = read(pipes[0], output, readsize);
	if (status == -1)
		ft_error("read failure");
	output[status] = '\0';

	
	dprintf(2, "strs: %s %s, amount read: %zu\n", output, input, status);
	if (strcmp(input, output) == 0)
		return (0);
	else
		return (-1);
}
