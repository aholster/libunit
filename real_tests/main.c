/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 21:49:40 by aholster       #+#    #+#                */
/*   Updated: 2019/05/06 21:32:10 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	t_unit	*lst;
	
	loadlaunch(&lst, "ATOI", atoi_launcher);
	loadlaunch(&lst, "ISALPHA", isalpha_launcher);
	loadlaunch(&lst, "ISDIGIT", isdigit_launcher);
	loadlaunch(&lst, "STRCMP", strcmp_launcher);
	loadlaunch(&lst, "STRLEN", strlen_launcher);
	activate_launchers(&lst, argc, argv);
	return (0);
}
