/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lu_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 15:08:23 by aholster       #+#    #+#                */
/*   Updated: 2019/05/22 15:08:39 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	lu_strncmp(char const *s1, char const *s2, size_t n)
{
	size_t index;

	index = 0;
	if (n == 0)
		return (0);
	while (s1[index] != '\0' && s2[index] != '\0' && index < (n - 1))
	{
		if (s1[index] != s2[index])
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		index++;
	}
	if (s1[index] != s2[index])
		return ((unsigned char)s1[index] - (unsigned char)s2[index]);
	return (0);
}
