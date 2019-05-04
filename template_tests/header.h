/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   header.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 16:26:05 by dsaripap       #+#    #+#                */
/*   Updated: 2019/05/04 15:45:22 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libunit.h"

# define READSIZE 6
/*
**	make sure readsize is a sufficiently large number
**	if you get read_errors, try changing READSIZE
**
**	fill in necesary includes and prototypes for tests bellow this line
*/

typedef struct	s_fds
{
	int		originfd;
	int		backupfd;
	int		pipes[2];
}				t_fds;

//# include "project_here.h"

# pragma mark prototypes

#endif
