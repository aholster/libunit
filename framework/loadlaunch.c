/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loadlaunch.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 18:03:30 by aholster       #+#    #+#                */
/*   Updated: 2019/04/25 18:24:00 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	loadlaunch(t_unit **alst, int (*f)(void))
{
	t_unit	*cur;

	cur = (t_unit *)malloc(sizeof(t_unit));
	if (cur == NULL)
		ft_error("malloc failure");
	cur->test = f;
	cur->name = NULL;
	cur->expectation = -4;
	cur->next = NULL;
	lu_lstaddend(alst, cur);
}
