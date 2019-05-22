/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lu_strnequ.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 15:09:05 by aholster       #+#    #+#                */
/*   Updated: 2019/05/22 15:09:53 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	lu_strnequ(char const *s1, char const *s2, size_t n)
{
	return (lu_strncmp(s1, s2, n) == 0);
}
