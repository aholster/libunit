/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strcmp_test01.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 20:44:06 by dsaripap       #+#    #+#                */
/*   Updated: 2019/04/24 13:41:25 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	diff_strcmp_test(void)
{
	if (ft_strcmp("Hello", "Hi") == strcmp("Hello", "Hi"))
		return (0);
	else
		return (-1);
}
