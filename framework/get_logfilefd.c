/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_logfilefd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/18 19:26:14 by aholster       #+#    #+#                */
/*   Updated: 2019/05/18 20:13:34 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static void	ft_specerror(char *error)
{
	lu_putstrstr_fd("\n\033[1;31mERROR:\033[0;33m%\033[0;00m\n", error, 2);
	raise(SIGKILL);
}

int			get_logfilefd(void)
{
	static int	logfile_fd = -1;

	if (logfile_fd == -1)
		logfile_fd = open(LOGFILE, O_RDWR | O_APPEND | O_TRUNC | O_CREAT, 0777);
	if (logfile_fd == -1)
		ft_specerror("Failed to create logfile");
	return (logfile_fd);
}
