/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   04_writing_clean_comparison.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 16:28:59 by aholster       #+#    #+#                */
/*   Updated: 2019/05/05 18:05:00 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdio.h>

int	advanced_clean_writing(void)
{
	char	*input;
	char	*ret;
	char	*ret_test;
	size_t	b_read;
	size_t	b_read_test;
	t_fds	fd_data;

	input = "***%9k";
	capture_fd(1, &fd_data);	
	printf("1234 %9%\n");
	b_read = retrieve_text(&ret, &fd_data);
	printf("1234 %9%\n");
	b_read_test = retrieve_text(&ret_test, &fd_data);
	reset_fd(&fd_data);
	
	dprintf(2, "strs: |%s| |%s|, amount read: %zu, %zu\n", ret, ret_test, b_read, b_read_test);
	if (b_read == b_read_test && strcmp(ret, ret_test) == 0)
		return (0);
	else
		return (-1);
}

int	main(void)
{
	printf("starting test\n");
	printf("return: %d \n", advanced_clean_writing());
	return (0);
}