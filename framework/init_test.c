/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_test.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 17:43:00 by aholster       #+#    #+#                */
/*   Updated: 2019/05/06 16:10:44 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	init_test(t_unit **lst, char *name, int (*test_ptr)(void))
{
	t_unit	*cur;

	cur = (t_unit *)malloc(sizeof(t_unit));
	if (cur == NULL)
		ft_error("malloc failed");
	cur->name = name;
	cur->test = test_ptr;
	cur->expectation = ok;
	cur->next = NULL;
	lu_lstaddend(lst, cur);
}
