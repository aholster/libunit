/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loadlaunch.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 18:03:30 by aholster       #+#    #+#                */
/*   Updated: 2019/05/06 21:27:53 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	loadlaunch(t_unit **alst, const char *block_name, int (*f)(void))
{
	t_unit	*cur;

	cur = (t_unit *)malloc(sizeof(t_unit));
	if (cur == NULL)
		ft_error("malloc failed");
	cur->test = f;
	cur->name = lu_strdup(block_name);
	if (cur->name == NULL)
		ft_error("malloc failed");
	cur->expectation = unexpect;
	cur->next = NULL;
	lu_lstaddend(alst, cur);
}
