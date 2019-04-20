/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lu_lstdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/22 17:40:24 by aholster       #+#    #+#                */
/*   Updated: 2019/04/20 18:39:52 by aholster      ########   odam.nl         */
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
		if (current->next != NULL)
			holder = current->next;
		else
			holder = NULL;
		free(current);
		current = holder;
	}
	*alst = NULL;
}
