/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strcmp_test01.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 20:44:06 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/04/21 21:11:52 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	diff_strcmp_test(void)
{
	if (ft_strcmp("Hello", "Hi") == strcmp("Hello", "Hi"))
		return (0);
	else
		return (-1);
}
