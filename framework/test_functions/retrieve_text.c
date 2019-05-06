/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   retrieve_text.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 18:36:33 by aholster       #+#    #+#                */
/*   Updated: 2019/05/05 18:32:48 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_functions.h"

static void		*lu_memcpy(void *dst, const void *src, size_t n)
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

static void		*lu_memjoin(const void *mem1, size_t size1,\
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

static size_t	stringerize(char **output, char *holder, size_t resultsize)
{
	*output = lu_memjoin(holder, resultsize, "\0", 1);
	if (*output == NULL)
		ft_error("malloc failed");
	return (resultsize);
}

size_t			retrieve_text(char **output, t_fds *fd_data)
{
	ssize_t	status;
	size_t	resultsize;
	char	temp[READSIZE];
	char	*holder;

	status = READSIZE;
	holder = (char *)malloc(1);
	if (holder == NULL)
		ft_error("malloc failed");
	resultsize = 0;
	while (status >= READSIZE)
	{
		status = read(fd_data->pipes[0], temp, READSIZE);
		if (status == -1 && errno == EAGAIN)
			break ;
		if (status == -1)
			ft_error("read failure");
		*output = lu_memjoin(holder, resultsize, temp, status);
		if (*output == NULL)
			ft_error("malloc failed");
		resultsize += status;
		free(holder);
		holder = *output;
	}
	return (stringerize(output, holder, resultsize));
}
