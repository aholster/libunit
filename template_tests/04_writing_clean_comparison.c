/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   04_writing_clean_comparison.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 16:28:59 by aholster       #+#    #+#                */
/*   Updated: 2019/05/03 16:47:49 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdio.h>

typedef struct	s_redir;
{
	int		originfd;
	int		backupfd;
	int		pipes[2];
}				t_redir;

int		capture_fd(int tarfd, t_redit *fd_data)
{
	if (pipe(fd_data->pipes) == -1)
		ft_error("pipes failure");
	if (dup2(tarfd, fd_data->backupfd) == -1)
		ft_error("failed to backup fd");
	if (close(tarfd) == -1)
		ft_error("failed to close fd");
	fd_data->originfd = tarfd;
	if (dup2(fd_data->pipes[1], 1) == -1)
		ft_error("failed to reroute fd");
	return (0);
}

int	advanced_writing(void)
{
	char	*output;
	char	*check;
	char	*input;
	t_redit	fd_data;

	readsize = 14;
	input = "one";

	capture_fd(1, &fd_data);

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
	status = read(pipes[0], check, readsize);
	if (status == -1)
		ft_error("read failure");
	check[status] = '\0';


	if (close(pipes[0]) == -1)
		ft_error("failed to close pipe");
	if (close(pipes[1]) == -1)
		ft_error("failed to close pipe");


	dprintf(2, "strs: %s %s, amount read: %zu\n", output, input, status);
	if (strcmp(input, output) == 0)
		return (0);
	else
		return (-1);
}
