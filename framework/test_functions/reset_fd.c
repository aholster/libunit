/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reset_fd.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/05 17:53:58 by aholster       #+#    #+#                */
/*   Updated: 2019/05/05 18:24:24 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_functions.h"

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
	fd_data->pipes[0] = -1;
	fd_data->pipes[1] = -1;
}
