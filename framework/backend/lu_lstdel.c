/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lu_lstdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/22 17:40:24 by aholster       #+#    #+#                */
/*   Updated: 2019/05/18 16:05:02 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	lu_lstdel(t_unit **alst)
{
	t_unit	*holder;
	t_unit	*current;

	if (alst == NULL || *alst == NULL)
		return ;
	current = *alst;
	while (current != NULL)
	{
		holder = current->next;
		free(current->name);
		free(current);
		current = holder;
	}
	*alst = NULL;
}
