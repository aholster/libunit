/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   isdigit_launcher.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 20:41:17 by dsaripap       #+#    #+#                */
/*   Updated: 2019/05/06 21:32:45 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	isdigit_launcher(void)
{
	t_unit	*lst;

	lst = NULL;
	init_test(&lst, "six_isdigit_test", six_isdigit_test);
	init_test(&lst, "w_isdigit_test", w_isdigit_test);
	init_test(&lst, "four_isdigit_test", four_isdigit_test);
	start_test(&lst);
	return (0);
}
