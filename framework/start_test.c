/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_test.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 17:51:51 by aholster       #+#    #+#                */
/*   Updated: 2019/04/20 21:49:06 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static void	putresult(int code)
{
	if (code == ok)
		lu_putstr(" \033[0;32mOK");
	else if (code == ko)
		lu_putstr(" \033[0;31mKO");
	else if (code == segv)
		lu_putstr(" \033[0;31mSEGV");
	else if (code == buse)
		lu_putstr(" \033[0;31mBUSE");
	else
		ft_error();
}

int			start_test(t_unit **lst, char *test)
{
	t_unit			*cur;
	int				neg;
	unsigned int	total;
	int				holder;

	cur = *lst;
	neg = 0;
	total = 0;
	holder = 0;
	lu_putstr("Now Testing: \033[0;34m");
	lu_putstr(test);
	lu_putstr("\033[0;00m\n\n");
	while (cur != NULL)
	{
		lu_putstr("	cur > \033[0;36m");
		lu_putstr(cur->name);
		holder = executioner(cur->test);
		if (holder != ok)
			neg -= -1;
		putresult(holder);
		lu_putendl("\033[0;00m");
		cur = cur->next;
		total += 1;
	}
	lu_putstr("\n		(");
	lu_putnbr(neg);
	lu_putstr("/");
	lu_putnbr(total);
	lu_putstr(") Tests passed\n\n");
	lu_lstdel(lst);
	return (neg);
}

// int 			main(void)
// {
// 	t_unit	*lst;

// 	lst = NULL;
// 	init_test(&lst, "test1", NULL);
// 	init_test(&lst, "test2", NULL);
// 	init_test(&lst, "test3", NULL);
// 	start_test(&lst, "STRLEN");
// 	return (0);
// }
