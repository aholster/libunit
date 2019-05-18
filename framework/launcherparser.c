/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   launcherparser.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/29 18:47:40 by aholster       #+#    #+#                */
/*   Updated: 2019/05/18 16:44:44 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static void		initarr(t_unit *lst, char **nametable,\
						int (**array)(void), size_t size)
{
	size_t	index;

	index = 0;
	while (index < size)
	{
		nametable[index] = lst->name;
		array[index] = lst->test;
		lst = lst->next;
		index++;
	}
}

static void		arrparser(char const *argument, char const **nametable,\
						int (**array)(void), size_t len)
{
	size_t	subdex;

	subdex = 0;
	while (subdex < len)
	{
		if (lu_strcmp(nametable[subdex], argument) == 0)
		{
			lu_putstrstr("\033[0;00m Now Testing:\033[0;34m %\033[0;00m\n\n",\
						nametable[subdex]);
			array[subdex]();
		}
		subdex++;
	}
}

void			launcherparser(t_unit *lst, size_t argc, char **argv)
{
	int		(**array)(void);
	char	**nametable;
	size_t	len;
	size_t	index;

	len = lu_lstlen(lst);
	array = (int (**)(void))malloc(sizeof(int (*)(void)) * len);
	nametable = (char **)malloc(sizeof(char *) * len);
	if (array == NULL || nametable == NULL)
		ft_error("malloc failed");
	initarr(lst, nametable, array, len);
	index = 0;
	while (index < argc)
	{
		arrparser(argv[index], (const char **)nametable, array, len);
		index++;
	}
	free(array);
	free(nametable);
}
