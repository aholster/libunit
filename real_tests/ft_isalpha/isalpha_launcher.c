/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   isalpha_launcher.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 20:45:43 by dsaripap       #+#    #+#                */
/*   Updated: 2019/04/25 14:19:06 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	isalpha_launcher(void)
{
	t_unit	*lst;

	lst = NULL;
	init_test(&lst, "d_isalpha_test", d_isalpha_test);
	init_test(&lst, "one_isalpha_test", one_isalpha_test);
	init_test(&lst, "dollar_isalpha_test", dollar_isalpha_test);
	start_test(&lst, "IS_ALPHA");
	return (0);
}
