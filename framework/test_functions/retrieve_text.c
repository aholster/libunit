/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   retrieve_text.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 18:36:33 by aholster       #+#    #+#                */
/*   Updated: 2019/05/06 21:27:00 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_functions.h"

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
