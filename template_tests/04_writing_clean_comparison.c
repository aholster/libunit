/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   04_writing_clean_comparison.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 16:28:59 by aholster       #+#    #+#                */
/*   Updated: 2019/05/03 21:38:59 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdio.h>
size_t		retrieve_text(char **output, t_fds *fd_data);

void	capture_fd(int tarfd, t_fds *fd_data)
{
	if (pipe(fd_data->pipes) == -1)
		ft_error("pipe creation failure");
	fd_data->backupfd = dup(tarfd);
	if (fd_data->backupfd == -1)
		ft_error("failed to backup fd");
	fd_data->originfd = tarfd;
	if (close(tarfd) == -1)
		ft_error("failed to close fd");
	if (dup2(fd_data->pipes[1], tarfd) == -1)
		ft_error("failed to reroute fd");
	if (fcntl(fd_data->pipes[0], F_SETFL, O_NONBLOCK) == -1)
		ft_error("failed to fcntl pipe");
}

/*
**	fnctl to set pipe read-end to non_block will result in read error
**	upon attempt to read empty pipe
*/

void	reset_fd(t_fds *fd_data)
{
	if (close(fd_data->pipes[0]) == -1)
		ft_error("failed to close pipe");
	if (close(fd_data->pipes[1]) == -1)
		ft_error("failed to close pipe");
	if (close(fd_data->originfd) == -1)
		ft_error("failed to close rerouted fd");
	if (dup2(fd_data->backupfd, fd_data->originfd) == -1)
		ft_error("failed to restore fd");
	if (close(fd_data->backupfd) == -1)
		ft_error("failed to close backup");
	fd_data->originfd = -1;
	fd_data->backupfd = -1;
	fd_data->pipes[0]= -1;
	fd_data->pipes[1] = -1;
}

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

int main(void)
{
	printf("begining test...\n");
	printf("return was %d \n", advanced_clean_writing());
	return (0);
}