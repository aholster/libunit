/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_test.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 17:51:51 by aholster       #+#    #+#                */
/*   Updated: 2019/04/25 14:32:01 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static void			putresult(int code, enum e_retcode expected)
{
	if (expected == ok)
	{
		if (code == ok)
			lu_putstr("\033[0;32m[OK]");
		else if (code == ko)
			lu_putstr("\033[0;31m[KO]");
		else if (code == segv)
			lu_putstr("\033[0;31m[SEGV]");
		else if (code == buse)
			lu_putstr("\033[0;31m[BUSE]");
		else if (code == timeout)
			lu_putstr("\033[0;33m[TIMEOUT]");
		else if (code == unexpect)
			lu_putstr("\033[0;31m[UNEXPECTED]");
		else
			ft_error();
		lu_putendl("\033[0;00m");
	}
}

static void			iterate(t_unit **cur, int *neg, unsigned int *total)
{
	enum e_retcode	holder;

	holder = 0;
	while ((*cur) != NULL)
	{
		lu_putstrstr("	> \033[0;36m%\033[0;00m ", (*cur)->name);
		holder = executioner((*cur)->test);
		if (holder != ok)
			*neg = *neg + 1;
		putresult(holder, (*cur)->expectation);
		(*cur) = (*cur)->next;
		(*total) += 1;
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
