/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strcmp_launcher.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 20:38:00 by dsaripap       #+#    #+#                */
/*   Updated: 2019/04/24 13:41:25 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	strcmp_launcher(void)
{
	t_unit	*lst;

	lu_putstr("\033[0;32m");
	lst = NULL;
	init_test(&lst, "diff_strcmp_test", diff_strcmp_test);
	init_test(&lst, "same_strcmp_test", same_strcmp_test);
	init_test(&lst, "empty_strcmp_test", empty_strcmp_test);
	start_test(&lst, "STR_CMP");
	return (0);
}
