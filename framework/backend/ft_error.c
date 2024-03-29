/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_error.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 17:47:11 by aholster       #+#    #+#                */
/*   Updated: 2019/05/18 20:18:01 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void			ft_error(char *error)
{
	lu_putstrstr_fd("\n\033[1;31mERROR:\033[0;33m%\033[0;00m\n", error, 2);
	lu_putstrstr_fd("\nERROR:%\n", error, get_logfilefd());
	raise(SIGKILL);
}
