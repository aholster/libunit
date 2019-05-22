/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lu_assert.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 13:10:52 by aholster       #+#    #+#                */
/*   Updated: 2019/05/22 21:38:20 by aholster      ########   odam.nl         */
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

void			unsignedll(unsigned long long num, const int fd);
void			signedll(long long num, const int fd);

void			lu_char(va_list ap, const int fd);
void			lu_str(va_list ap, const int fd);
void			lu_mem(va_list ap, const int fd);

void			lu_digit(va_list ap, const int fd);
void			lu_digit_ll(va_list ap, const int fd);
void			lu_digit_l(va_list ap, const int fd);
void			lu_digit_h(va_list ap, const int fd);
void			lu_digit_hh(va_list ap, const int fd);

void			lu_unsign(va_list ap, const int fd);
void			lu_unsign_ll(va_list ap, const int fd);
void			lu_unsign_l(va_list ap, const int fd);
void			lu_unsign_h(va_list ap, const int fd);
void			lu_unsign_hh(va_list ap, const int fd);

#endif
