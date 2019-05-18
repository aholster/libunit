/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lu_lstlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/18 16:07:39 by aholster       #+#    #+#                */
/*   Updated: 2019/05/18 16:37:05 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

size_t	lu_lstlen(t_unit const *lst)
{
	size_t	len;

	len = 0;
	if (lst == NULL)
		return (len);
	while (lst != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
