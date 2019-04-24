/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strlen_launcher.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 20:36:30 by dsaripap       #+#    #+#                */
/*   Updated: 2019/04/24 13:41:30 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	strlen_launcher(void)
{
	t_unit	*lst;

	lu_putstr("\033[0;32m");
	lst = NULL;
	init_test(&lst, "barcelona_strlen_test", barcelona_strlen_test);
	init_test(&lst, "aristotle_strlen_test", aristotle_strlen_test);
	init_test(&lst, "strlen_test03", strlen_test03);
	start_test(&lst, "STR_LEN");
	return (0);
}
