/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   launcherparser.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/29 18:47:40 by aholster       #+#    #+#                */
/*   Updated: 2019/05/06 21:34:11 by aholster      ########   odam.nl         */
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
	size_t	index;
	int		(**array)(void);
	int		num;
	size_t	len;

	index = 0;
	len = lstlen(alst);
	array = (int (**)(void))malloc(sizeof(int (*)(void)) * len);
	if (array == NULL)
		ft_error("malloc failed");
	while (index < len)
	{
		array[index] = (*alst)->test;
		(*alst) = (*alst)->next;
		index++;
	}
	index = 0;
	while (index < argc)
	{
		num = lu_atoi(argv[index]);
		if (num > 0 && (size_t)num <= len)
		{
			lu_putstrstr("\033[0;00m Now Testing:\033[0;34m %\033[0;00m\n\n", (*alst)->name);
			(array[num - 1])();
		}
		index++;
	}
}
