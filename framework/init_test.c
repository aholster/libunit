/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_test.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 17:43:00 by aholster       #+#    #+#                */
/*   Updated: 2019/05/18 17:19:07 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	init_test(t_unit **lst, const char *name, t_test test_ptr)
{
	t_unit	*cur;

	cur = (t_unit *)malloc(sizeof(t_unit));
	if (cur == NULL)
		ft_error("malloc failed");
	cur->name = lu_strdup(name);
	if (cur->name == NULL)
		ft_error("malloc failed");
	cur->test = test_ptr;
	cur->expectation = ok;
	cur->next = NULL;
	lu_lstaddend(lst, cur);
}
