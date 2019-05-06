/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lu_memjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/06 21:26:24 by aholster       #+#    #+#                */
/*   Updated: 2019/05/06 21:27:28 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void		*lu_memjoin(const void *mem1, size_t size1,\
					const void *mem2, size_t size2)
{
	size_t	index;
	char	*ret;

	index = 0;
	ret = (char *)malloc(sizeof(char) * size1 + size2);
	if (ret == NULL)
		return (NULL);
	lu_memcpy(ret, mem1, size1);
	lu_memcpy(&ret[size1], mem2, size2);
	return (ret);
}
