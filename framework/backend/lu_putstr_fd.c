/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lu_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 17:42:44 by aholster       #+#    #+#                */
/*   Updated: 2019/05/02 17:45:01 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	lu_putstr_fd(char const *s, int fd)
{
	write(fd, s, lu_strlen(s));
}
