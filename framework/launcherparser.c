/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   launcherparser.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/29 18:47:40 by aholster       #+#    #+#                */
/*   Updated: 2019/04/30 15:56:06 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static size_t	lstlen(t_unit **alst)
{
	t_unit	*temp;
	size_t	len;

	len = 0;
	temp = *alst;
	if (temp == NULL)
		return (len);
	while (temp != NULL)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

void			launcherparser(t_unit **alst, size_t argc, char **argv)
{
	size_t	i;
	int		(**array)(void);
	int		num;
	size_t	len;

	i = 0;
	len = lstlen(alst);
	array = (int (**)(void))malloc(sizeof(int (*)(void)) * len);
	while (i < len)
	{
		array[i] = (*alst)->test;
		(*alst) = (*alst)->next;
		i++;
	}
	i = 0;
	while (i < argc)
	{
		num = lu_atoi(argv[i]);
		if (num > 0 && (size_t)num <= len)
			(array[num - 1])();
		i++;
	}
}