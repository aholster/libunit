/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_test.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 17:51:51 by aholster       #+#    #+#                */
/*   Updated: 2019/05/05 21:29:52 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static void			iterate(t_unit **cur, int *neg, unsigned int *total)
{
	t_retcode	holder;

	holder = 0;
	while ((*cur) != NULL)
	{
		lu_putstrstr("	\033[0;36m%\033[0;00m > ", (*cur)->name);
		holder = executioner((*cur)->test);
		if (putresult(holder, (*cur)->expectation) == -1)
			*neg = *neg + 1;
		lu_putendl("\033[0;00m");
		(*cur) = (*cur)->next;
		(*total)++;
	}
}

int					start_test(t_unit **lst, char *test)
{
	t_unit			*cur;
	int				neg;
	unsigned int	total;

	cur = *lst;
	neg = 0;
	total = 0;
	lu_putstrstr("\033[0;00m Now Testing:\033[0;34m %\033[0;00m\n\n", test);
	iterate(&cur, &neg, &total);
	lu_putstr("\n		(");
	lu_putnbr(total - neg);
	lu_putstr("/");
	lu_putnbr(total);
	lu_putstr(") Tests passed\n\n");
	lu_lstdel(lst);
	return (neg);
}
