/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_functions.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/05 15:31:56 by aholster       #+#    #+#                */
/*   Updated: 2019/05/22 13:28:26 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_FUNCTIONS_H
# define TEST_FUNCTIONS_H

# include "./../libunit.h"

# include <string.h>
# include <limits.h>

typedef struct	s_fds
{
	int			originfd;
	int			backupfd;
	int			pipes[2];
}				t_fds;

# ifndef READSIZE
#  define READSIZE 64
# endif

size_t			retrieve_text(char **output, t_fds *fd_data);
void			capture_fd(int tarfd, t_fds *fd_data);
void			reset_fd(t_fds *fd_data);

#endif
