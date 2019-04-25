/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_advtest.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 14:21:04 by aholster       #+#    #+#                */
/*   Updated: 2019/04/25 14:41:07 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	init_advtest(t_unit **lst, char *name, enum e_retcode expected_result,
 int (*f)(void))
{
	t_unit	*cur;

	cur = (t_unit *)malloc(sizeof(t_unit));
	if (cur == NULL)
		ft_error("malloc failure");
	cur->name = name;
	cur->test = f;
	cur->expectation = expected_result;
	cur->next = NULL;
	lu_lstaddend(lst, cur);
}
