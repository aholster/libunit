/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   03_writing_comparison.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 17:34:37 by aholster       #+#    #+#                */
/*   Updated: 2019/05/19 18:39:25 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdio.h>
int	advanced_writing(void)
{
	char	*output;
	char	*check;
	char	*input;
	size_t	index;
	size_t	readsize;
	ssize_t	status;
	ssize_t status_check;
	int		pipes[2];

	readsize = 14;
	input = "one";
	index = 0;

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

	write(1, input, 3);

	check = (char *)malloc(sizeof(char) * readsize + 1);
	if (check == NULL)
		ft_error("malloc failed");
	status_check = read(pipes[0], check, readsize);
	if (status_check == -1)
		ft_error("read failure");
	check[status_check] = '\0';


	if (close(pipes[0]) == -1)
		ft_error("failed to close pipe");
	if (close(pipes[1]) == -1)
		ft_error("failed to close pipe");

	assert((status == status_check), "status |%d| does not status_check |%d|", status, status_check);
	while (input[index] != '\0')
	{
		assert((input[index] == output[index]),\
		"input |%c| did not match output |%c| at index |%u|", input[index], output[index], index);
		index++;
	}
	return (0);
}
