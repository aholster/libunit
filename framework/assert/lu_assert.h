/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lu_assert.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 13:10:52 by aholster       #+#    #+#                */
/*   Updated: 2019/05/31 18:58:22 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LU_ASSERT_H
# define LU_ASSERT_H

# include "./../libunit.h"

# include <stdarg.h>
# include <stdio.h>

typedef enum	e_assertcode
{
	retrieve = 42,
	testfail = -1,
	testsuccess = 0
}				t_assertcode;

void			assert(int expression, const char *format, ...);
void			softassert(int expression, const char *format, ...);
int				assert_status(t_assertcode code);

void			assert_format(va_list ap, const char *format, const int fd);

#endif
