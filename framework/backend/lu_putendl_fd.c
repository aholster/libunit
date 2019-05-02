/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lu_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 17:44:39 by aholster       #+#    #+#                */
/*   Updated: 2019/05/02 17:49:54 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	lu_putendl_fd(char const *s, int fd)
{
	write(fd, s, lu_strlen(s));
	write(fd, "\n", 1);
}
