/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strcmp_test02.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 20:44:15 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/04/21 21:11:01 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	same_strcmp_test(void)
{
	if (ft_strcmp("Amsterdam", "Amsterdam") == strcmp("Amsterdam", "Amsterdam"))
		return (0);
	else
		return (-1);
}
