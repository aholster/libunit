/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   isdigit_launcher.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 20:41:17 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/04/21 21:14:06 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	isdigit_launcher(void)
{
	t_unit	*lst;

	lu_putstr("\033[0;32m");
	lst = NULL;
	init_test(&lst, "six_isdigit_test", six_isdigit_test);
	init_test(&lst, "w_isdigit_test", w_isdigit_test);
	init_test(&lst, "four_isdigit_test", four_isdigit_test);
	start_test(&lst, "IS_DIGIT");
	return (0);
}
