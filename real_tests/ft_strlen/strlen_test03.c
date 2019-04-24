/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strlen_test03.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 21:04:41 by dsaripap       #+#    #+#                */
/*   Updated: 2019/04/24 13:41:25 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	strlen_test03(void)
{
	if (ft_strlen("Know Thyself, Socrates") == strlen("Know Thyself, Socrates"))
		return (0);
	else
		return (-1);
}
