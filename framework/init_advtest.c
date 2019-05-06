/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_advtest.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 14:21:04 by aholster       #+#    #+#                */
/*   Updated: 2019/05/06 16:10:45 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	init_advtest(t_unit **lst, char *name, t_retcode expected_result,
	int (*test_ptr)(void))
{
	t_unit	*cur;

	cur = (t_unit *)malloc(sizeof(t_unit));
	if (cur == NULL)
		ft_error("malloc failure");
	cur->name = name;
	cur->test = test_ptr;
	cur->expectation = expected_result;
	cur->next = NULL;
	lu_lstaddend(lst, cur);
}
