/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   atoi_test03.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 20:54:58 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/04/21 21:18:02 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	atoi_minus_test(void)
{
	if (ft_atoi("    -9332") == atoi("    -9332"))
		return (0);
	else
		return (-1);
}
