/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   isalpha_test02.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 20:46:05 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/04/21 21:15:46 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	one_isalpha_test(void)
{
	if (ft_isalpha('1') == 0)
		return (0);
	else
		return (-1);
}
