/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lu_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 17:59:46 by aholster       #+#    #+#                */
/*   Updated: 2019/04/20 18:05:50 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	lu_putstr(char const *s)
{
	write(1, s, lu_strlen(s));
}
