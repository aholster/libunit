/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   05_writing_printf_comparison_test.c                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/21 16:27:12 by jesmith        #+#    #+#                */
/*   Updated: 2019/05/22 20:29:57 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdio.h>

int	writing_printf_comparison_test(void)
{
	char	*ret;
	char	*ret_test;
	char	*input;
	size_t	index;
	int		byt;
	int		byt_test;
	size_t	b_read;
	size_t	b_read_test;
	t_fds	fd_data;

	index = 0;
	input = "";
	capture_fd(1, &fd_data);

	byt = printf(input);
	fflush(stdout);

	b_read = retrieve_text(&ret, &fd_data);

	byt_test = ft_printf(input);

	b_read_test = retrieve_text(&ret_test, &fd_data);
	softassert(((byt == b_read) && (byt_test == b_read_test) && (b_read == b_read_test)),\
		"printf: ret |%d| b_read |%u| ft_printf: ret |%d| b_read |%u|",\
		byt, b_read, byt_test, b_read_test);
	reset_fd(&fd_data);
	while (ret[index] != '\0')
	{
		assert((ret[index] == ret_test[index]),\
			"printf |%c| |%m| did not match ft_printf |%c| |%m| at index |%u|",\
			ret[index], index, ret, ret_test[index], index, ret_test, index);
		index++;
	}
	return (0);
}
