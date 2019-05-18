/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_test.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 17:51:51 by aholster       #+#    #+#                */
/*   Updated: 2019/05/18 17:33:18 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

// static void			iterate(t_unit **current, int *failed_tests,\
// 							unsigned int *total)
// {
// 	t_retcode	holder;

// 	holder = 0;
// 	while ((*current) != NULL)
// 	{
// 		lu_putstrstr("	\033[0;36m%\033[0;00m > ", (*current)->name);
// 		holder = executioner((*current)->test);
// 		if (putresult(holder, (*current)->expectation) == -1)
// 			*failed_tests = *failed_tests + 1;
// 		lu_putendl("\033[0;00m");
// 		(*current) = (*current)->next;
// 		(*total)++;
// 	}
// }

// int					start_test(t_unit **lst)
// {
// 	t_unit			*current;
// 	int				failed_tests;
// 	unsigned int	total;

// 	current = *lst;
// 	failed_tests = 0;
// 	total = 0;
// 	iterate(&current, &failed_tests, &total);
// 	lu_putstr("\n		(");
// 	lu_putnbr(total - failed_tests);
// 	lu_putstr("/");
// 	lu_putnbr(total);
// 	lu_putstr(") Tests passed\n\n");
// 	lu_lstdel(lst);
// 	return (failed_tests);
// }

int					start_test(t_unit **alst)
{
	t_unit			*current;
	int				failed_tests;
	unsigned int	total;

	current = *alst;
	failed_tests = 0;
	total = lu_lstlen(current);
	while ((current) != NULL)
	{
		lu_putstrstr("	\033[0;36m%\033[0;00m > ", current->name);
		if (putresult(executioner(current->test), current->expectation) == -1)
			failed_tests = failed_tests + 1;
		lu_putendl("\033[0;00m");
		current = current->next;
	}
	lu_putstr("\n		(");
	lu_putnbr(total - failed_tests);
	lu_putstr("/");
	lu_putnbr(total);
	lu_putstr(") Tests passed\n\n");
	lu_lstdel(alst);
	return (failed_tests);
}
