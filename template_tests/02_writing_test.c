/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   02_writing_test.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 16:54:19 by aholster       #+#    #+#                */
/*   Updated: 2019/05/08 15:19:51 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdio.h>
int	basic_writing(void)
{
	char	*output;
	char	*input;
	size_t	b_read;
	t_fds	fd_data;

	input = "one";

	capture_fd(1, &fd_data);
	lu_putstr(input);
	b_read = retrieve_text(&output, &fd_data);
	reset_fd(&fd_data);
	
	dprintf(2, "strs: %s %s, amount read: %zu\n", output, input, b_read);
	if (strcmp(input, output) == 0)
		return (0);
	else
		return (-1);
}
