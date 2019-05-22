/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   05_writing_printf_comparison.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/21 16:27:12 by jesmith        #+#    #+#                */
/*   Updated: 2019/05/22 19:04:22 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
	
	softassert(((byt == b_read) && (byt_test == b_read_test) && \ 
	(b_read == b_read_test)), \
	"printf: ret |%d| b_read |%u| ft_printf: ret |%d| b_read |%u|", \
	byt, b_read, byt_test, b_read_test);	
	reset_fd(&fd_data);
	
	while (ret[index] != '\0')
	{
		assert((ret[index] == ret_test[index]),\
		"printf |%c| did not match ft_printf |%c| at index |%u| in string |%m|", \
		ret[index], ret_test[index], index, 48, str);
		index++;
	}
	return (0);
}
