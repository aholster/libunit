/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   atoi_launcher.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 20:54:12 by dsaripap       #+#    #+#                */
/*   Updated: 2019/04/25 14:19:01 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	atoi_launcher(void)
{
	t_unit	*lst;

	lst = NULL;
	init_test(&lst, "positive_test", atoi_positive_test);
	init_test(&lst, "doublesign_test", atoi_doublesign_test);
	init_test(&lst, "minus_test", atoi_minus_test);
	start_test(&lst, "ATOI");
	return (0);
}
