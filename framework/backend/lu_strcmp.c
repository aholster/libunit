/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lu_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/18 16:25:23 by aholster       #+#    #+#                */
/*   Updated: 2019/05/18 16:26:00 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	lu_strcmp(char const *s1, char const *s2)
{
	size_t	index;

	index = 0;
	while (s1[index] == s2[index] && s2[index] != '\0' && s1[index] != '\0')
	{
		index++;
	}
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}
