/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_test.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 17:51:51 by aholster       #+#    #+#                */
/*   Updated: 2019/05/31 19:54:56 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static int			find_longest_name(const t_unit *lst)
{
	int		namelen;
	int		holder;

	namelen = 0;
	while (lst != NULL)
	{
		holder = (int)lu_strlen(lst->name);
		if (holder > namelen)
			namelen = holder;
		lst = lst->next;
	}
	return (namelen);
}

static int			result_handler(t_unit *current, const int fd)
{
	t_retcode	holder;

	holder = executioner(current->test);
	logresult(holder, current->expectation, fd);
	if (putresult(holder, current->expectation) == -1)
		return (-1);
	return (1);
}

void				start_test(t_unit **alst)
{
	t_unit			*current;
	unsigned int	failed_tests;
	unsigned int	total;
	int				padding;

	current = *alst;
	failed_tests = 0;
	total = lu_lstlen(current);
	padding = find_longest_name(current);
	while (current != NULL)
	{
		dprintf(1, "\t\033[0;36m%-*s\033[0;00m > ", padding, current->name);
		dprintf(get_logfilefd(), "\n\n\t%-*s > ", padding, current->name);
		if (result_handler(current, get_logfilefd()) == -1)
			failed_tests++;
		lu_putendl("");
		current = current->next;
	}
	dprintf(1, "\n\t\t(%u/%u) Tests passed\n\n", total - failed_tests, total);
	lu_lstdel(alst);
}
