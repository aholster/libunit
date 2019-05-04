/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   isalpha_test01.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 20:45:56 by dsaripap       #+#    #+#                */
/*   Updated: 2019/05/04 16:00:14 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	d_isalpha_test(void)
{
	ft_error("purposeful crash");
	if (ft_isalpha('d') == 1)
		return (0);
	else
		return (-1);
}
