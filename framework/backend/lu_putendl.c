/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lu_putendl.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:28:32 by aholster       #+#    #+#                */
/*   Updated: 2019/04/20 18:05:54 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	lu_putendl(char const *s)
{
	write(1, s, lu_strlen(s));
	write(1, "\n", 1);
}
