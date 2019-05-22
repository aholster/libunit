/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lu_assert.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 13:10:52 by aholster       #+#    #+#                */
/*   Updated: 2019/05/22 13:46:11 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LU_ASSERT_H
# define LU_ASSERT_H

# include "./../libunit.h"

# include <stdarg.h>

typedef enum	e_assertcode
{
	retrieve = 42,
	testfail = -1,
	testsuccess = 0,
	reset = -42
}				t_assertcode;

void			assert(int expression, const char *format, ...);
void			softassert(int expression, const char *format, ...);

void			assert_format(va_list ap, const char *format, const int fd);

void			unsignedll(unsigned long long num, const int fd);
void			signedll(long long num, const int fd);
void			lu_char(va_list ap, const int fd);
void			lu_digit(va_list ap, const int fd);
void			lu_str(va_list ap, const int fd);
void			lu_unsign(va_list ap, const int fd);

int				final_assert(void);

#endif
