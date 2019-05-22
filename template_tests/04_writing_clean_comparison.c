/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   04_writing_clean_comparison.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 16:28:59 by aholster       #+#    #+#                */
/*   Updated: 2019/05/22 20:26:03 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdio.h>

int	advanced_clean_writing(void)
{
	char	*input;
	char	*ret;
	char	*ret_test;
	size_t	index;
	size_t	b_read;
	size_t	b_read_test;
	t_fds	fd_data;

	index = 0;
	input = "";
	capture_fd(1, &fd_data);

	printf("");

	b_read = retrieve_text(&ret, &fd_data);

	printf("");

	b_read_test = retrieve_text(&ret_test, &fd_data);
	reset_fd(&fd_data);
	assert((b_read == b_read_test), "b_read printf |%d| does not match |%d|",\
		b_read, b_read_test);
	while (ret[index] != '\0')
	{
		assert((ret[index] == ret_test[index]),\
			"printf |%c| did not match ft_printf |%c| at index |%u|",\
			ret[index], ret_test[index], index);
		index++;
	}
}
