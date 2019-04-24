/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   isalpha_test01.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 20:45:56 by dsaripap       #+#    #+#                */
/*   Updated: 2019/04/24 13:41:25 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	d_isalpha_test(void)
{
	if (ft_isalpha('d') == 1)
		return (0);
	else
		return (-1);
}
