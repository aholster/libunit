/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lu_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/06 21:25:05 by aholster       #+#    #+#                */
/*   Updated: 2019/05/06 21:25:32 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void		*lu_memcpy(void *dst, const void *src, size_t n)
{
	size_t	index;

	index = 0;
	while (n - index >= 8)
	{
		*((long long *)(dst + index)) = *((long long *)(src + index));
		index += 8;
	}
	while (index < n)
	{
		((char *)dst)[index] = ((const char *)src)[index];
		index++;
	}
	return (dst);
}
