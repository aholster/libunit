/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   02_writing_test.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 16:54:19 by aholster       #+#    #+#                */
/*   Updated: 2019/04/30 16:54:49 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	basic_writing(void)
{
	if (output == expected)
		return (0);
	else
		return (-1);
}
