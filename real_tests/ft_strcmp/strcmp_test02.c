/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strcmp_test02.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 20:44:15 by dsaripap       #+#    #+#                */
/*   Updated: 2019/04/24 13:41:25 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	same_strcmp_test(void)
{
	if (ft_strcmp("Amsterdam", "Amsterdam") == strcmp("Amsterdam", "Amsterdam"))
		return (0);
	else
		return (-1);
}
