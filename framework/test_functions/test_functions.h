/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_functions.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/05 15:31:56 by aholster       #+#    #+#                */
/*   Updated: 2019/05/08 20:17:31 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_FUNCTIONS_H
# define TEST_FUNCTIONS_H

# include "libunit.h"

# include <stdarg.h>
# include <string.h>
# include <limits.h>

typedef struct	s_fds
{
	int			originfd;
	int			backupfd;
	int			pipes[2];
}				t_fds;

typedef void (*t_wrtfunc)(va_list, const int);

# ifndef READSIZE
#  define READSIZE 6
# endif


size_t			retrieve_text(char **output, t_fds *fd_data);
void			capture_fd(int tarfd, t_fds *fd_data);
void			reset_fd(t_fds *fd_data);

void			assert(int expression, const char *format, ...);
void			unsignedll(unsigned long long num, const int fd)
void			signedll(long long num, const int fd)
void			lu_char(va_list ap, const int fd)
void			lu_digit(va_list ap, const int fd)
void			lu_str(va_list ap, const int fd)
void			lu_unsign(va_list ap, const int fd)

#endif
