/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   isdigit_test02.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 20:42:52 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/04/21 23:34:27 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	w_isdigit_test(void)
{
	if (ft_isdigit(':') == 0)
		return (0);
	else
		return (-1);
}
