/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   isdigit_test03.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 20:43:03 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/04/21 21:13:00 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	four_isdigit_test(void)
{
	if (ft_isdigit('4') == 1)
		return (0);
	else
		return (-1);
}
