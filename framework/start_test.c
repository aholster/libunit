/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_test.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 17:51:51 by aholster       #+#    #+#                */
/*   Updated: 2019/05/22 17:30:59 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static void			putfailcount(const unsigned int failed_tests,\
								const unsigned int total)
{
	lu_putstr("\n		(");
	lu_putnbr(total - failed_tests);
	lu_putstr("/");
	lu_putnbr(total);
	lu_putstr(") Tests passed\n\n");
}

void				start_test(t_unit **alst)
{
	t_unit			*current;
	unsigned int	failed_tests;
	unsigned int	total;

	current = *alst;
	failed_tests = 0;
	total = lu_lstlen(current);
	while (current != NULL)
	{
		lu_putstrstr("	\033[0;36m%\033[0;00m > ", current->name);
		lu_putstrstr_fd("\n	% > ", current->name, get_logfilefd());
		if (putresult(executioner(current->test), current->expectation) == -1)
			failed_tests++;
		lu_putendl("\033[0;00m");
		current = current->next;
	}
	putfailcount(failed_tests, total);
	lu_lstdel(alst);
}
