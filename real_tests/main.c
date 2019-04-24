/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 21:49:40 by aholster       #+#    #+#                */
/*   Updated: 2019/04/24 13:40:41 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(void)
{
	lu_putstr("\033[0;35m");
	lu_putstr("\n*******************************************\n");
	lu_putstr("*                                         * \n");
	lu_putstr("*    Testing Microframework :  Libunit    * \n");
	lu_putstr("*                                         * \n");
	lu_putstr("*******************************************\n\n");
	atoi_launcher();
	isalpha_launcher();
	isdigit_launcher();
	strcmp_launcher();
	strlen_launcher();
	lu_putstr("\033[0;35m");
	lu_putstr("\n*******************************************\n");
	lu_putstr("*     Testing execution was completed     * \n");
	lu_putstr("*******************************************\n\n");
	return (0);
}
