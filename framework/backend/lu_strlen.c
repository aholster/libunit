/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lu_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 13:39:30 by aholster       #+#    #+#                */
/*   Updated: 2019/04/20 17:58:34 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

size_t	lu_strlen(char const *s)
{
	size_t index;

	index = 0;
	while (s[index] != '\0')
		index++;
	return (index);
}
