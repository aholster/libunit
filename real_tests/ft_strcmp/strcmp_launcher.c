/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strcmp_launcher.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 20:38:00 by dsaripap       #+#    #+#                */
/*   Updated: 2019/05/06 21:32:41 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	strcmp_launcher(void)
{
	t_unit	*lst;

	lst = NULL;
	init_test(&lst, "diff_strcmp_test", diff_strcmp_test);
	init_test(&lst, "same_strcmp_test", same_strcmp_test);
	init_test(&lst, "empty_strcmp_test", empty_strcmp_test);
	start_test(&lst);
	return (0);
}
