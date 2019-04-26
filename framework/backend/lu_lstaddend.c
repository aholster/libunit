/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lu_lstaddend.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 17:45:44 by aholster       #+#    #+#                */
/*   Updated: 2019/04/20 18:47:15 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

t_unit	*lu_lstaddend(t_unit **lst, t_unit *new)
{
	t_unit *internal;

	if (*lst == NULL)
	{
		*lst = new;
		return (new);
	}
	internal = *lst;
	while (internal->next != NULL)
	{
		internal = internal->next;
	}
	internal->next = new;
	return (new);
}
