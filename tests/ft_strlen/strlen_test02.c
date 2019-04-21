/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strlen_test02.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 20:35:46 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/04/21 23:29:30 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	aristotle_strlen_test(void)
{
	char *p;
	p = NULL;
	if (ft_strlen(p) == strlen(p))
		return (0);
	else
		return (-1);
}
