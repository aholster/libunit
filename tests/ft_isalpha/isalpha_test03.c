/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   isalpha_test03.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 20:46:15 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/04/21 21:15:13 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	dollar_isalpha_test(void)
{
	if (ft_isalpha('$') == 0)
		return (0);
	else
		return (-1);
}
