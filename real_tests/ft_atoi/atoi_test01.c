/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   atoi_test01.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 20:54:38 by dsaripap       #+#    #+#                */
/*   Updated: 2019/04/24 13:41:25 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	atoi_positive_test(void)
{
	if (ft_atoi("     90678") == atoi("     90678"))
		return (0);
	else
		return (-1);
}
