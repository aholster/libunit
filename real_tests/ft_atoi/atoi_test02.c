/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   atoi_test02.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 20:54:49 by dsaripap       #+#    #+#                */
/*   Updated: 2019/04/24 13:41:25 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	atoi_doublesign_test(void)
{
	if (ft_atoi("  ++878137") == atoi("  ++878137"))
		return (0);
	else
		return (-1);
}
