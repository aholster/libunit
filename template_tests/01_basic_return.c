/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   01_basic_return.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 16:45:59 by aholster       #+#    #+#                */
/*   Updated: 2019/05/22 20:25:10 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	basic_return(void)
{
	void	*input;
	void	expected;
	void	output;

	input = "";
	expected = "";
	output = func(input);

	assert((output == expected),"output |%| did not match expected |%|",\
	output, input);
	return (0);
}
