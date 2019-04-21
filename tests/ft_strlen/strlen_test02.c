/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strlen_test02.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 20:35:46 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/04/21 21:05:40 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	aristotle_strlen_test(void)
{
	if (ft_strlen("Thales of Miletus") == strlen("Thales of Miletus"))
		return (0);
	else
		return (-1);
}
