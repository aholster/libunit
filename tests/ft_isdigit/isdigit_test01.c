/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   isdigit_test01.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 20:42:42 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/04/21 21:06:56 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	six_isdigit_test(void)
{
	if (ft_isdigit('6') == 1)
		return (0);
	else
		return (-1);
}
