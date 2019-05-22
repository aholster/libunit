/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   02_writing_test.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 16:54:19 by aholster       #+#    #+#                */
/*   Updated: 2019/05/22 20:25:25 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	basic_writing(void)
{
	char	*output;
	char	*input;
	size_t	index;
	size_t	b_read;
	t_fds	fd_data;

	index = 0;
	input = "one";
	capture_fd(1, &fd_data);
	
	lu_putstr(input);

	b_read = retrieve_text(&output, &fd_data);
	reset_fd(&fd_data);
	while (input[index] != '\0')
	{
		assert((input[index] == output[index]),\
			"input |%c| did not match output |%c| at index |%u|",\
			input[index], output[index], index);
		index++;
	}
	return (0);
}
