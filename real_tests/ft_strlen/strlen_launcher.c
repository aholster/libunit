/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strlen_launcher.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 20:36:30 by dsaripap       #+#    #+#                */
/*   Updated: 2019/04/25 16:36:52 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	strlen_launcher(void)
{
	t_unit	*lst;

	lst = NULL;
	init_test(&lst, "barcelona_strlen_test", barcelona_strlen_test);
	init_advtest(&lst, "aristotle_strlen_test", ok, aristotle_strlen_test);
	init_test(&lst, "strlen_test03", strlen_test03);
	init_advtest(&lst, "warning_infinite_loop", timeout, infiniteloop);
	start_test(&lst, "STR_LEN");
	return (0);
}
