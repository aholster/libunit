/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   capture_fd.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/05 17:52:49 by aholster       #+#    #+#                */
/*   Updated: 2019/05/05 17:53:16 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_functions.h"

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
