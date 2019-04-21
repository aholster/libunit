/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strcmp_test03.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 20:40:20 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/04/21 21:12:12 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	empty_strcmp_test(void)
{
	if (ft_strcmp("", "") == strcmp("", ""))
		return (0);
	else
		return (-1);
}
