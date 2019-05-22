/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lu_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:45:21 by aholster       #+#    #+#                */
/*   Updated: 2019/05/22 18:17:38 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	lu_putchar_fd(char c, const int fd)
{
	write(fd, &c, 1);
}
