/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strlen_test01.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 20:37:09 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/04/21 21:08:01 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	barcelona_strlen_test(void)
{
	if (ft_strlen("Barcelona") == strlen("Barcelona"))
		return (0);
	else
		return (-1);
}
