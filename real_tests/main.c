/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 21:49:40 by aholster       #+#    #+#                */
/*   Updated: 2019/04/26 16:09:50 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	t_unit	*lst;
	
	loadlaunch(&lst, atoi_launcher);
	loadlaunch(&lst, isalpha_launcher);
	loadlaunch(&lst, isdigit_launcher);
	loadlaunch(&lst, strcmp_launcher);
	loadlaunch(&lst, strlen_launcher);
	activate_launchers(&lst, argc, argv);
	return (0);
}
