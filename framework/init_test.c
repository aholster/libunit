/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_test.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 17:43:00 by aholster       #+#    #+#                */
/*   Updated: 2019/04/20 18:46:50 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	init_test(t_unit **lst, char *name, int (*f)(void))
{
	t_unit	*cur;

	cur = (t_unit *)malloc(sizeof(t_unit));
	if (cur == NULL)
		ft_error();
	cur->name = name;
	cur->test = f;
	cur->next = NULL;
	lu_lstaddend(lst, cur);
}
