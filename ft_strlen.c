/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 17:34:34 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/04/09 20:28:42 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

size_t		ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}
