/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libunit.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 15:51:10 by aholster       #+#    #+#                */
/*   Updated: 2019/05/20 18:52:16 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# define TIMEOUT 5

# define LOGFILE "LOG_FILE"

# define TRUE 1
# define FALSE 0

# include "test_functions.h"

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

# include <string.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <fcntl.h>

typedef int		(*t_test)(void);

typedef enum		e_retcode
{
	ok = 1,
	ko = 0,
	segv = -1,
	buse = -2,
	timeout = -3,
	unexpect = -4
}					t_retcode;

typedef	struct		s_unit
{
	char			*name;
	t_test			test;
	t_retcode		expectation;
	struct s_unit	*next;
}					t_unit;

void				ft_error(char *error);
int					putresult(t_retcode code, t_retcode expected);
void				init_test(t_unit **lst, const char *name, t_test test_ptr);
void				init_advtest(t_unit **lst, const char *name, \
					t_retcode expected_result, t_test test_ptr);
t_retcode			executioner(t_test test_ptr);
void				start_test(t_unit **alst);

void				loadlaunch(t_unit **alst, const char *block_name,\
					t_test f);
void				activate_launchers(t_unit **alst, int argc, char **argv);
void				launcherparser(t_unit *lst, size_t argc, char **argv);

int					get_logfilefd(void);

void				*lu_memcpy(void *dst, const void *src, size_t n);
void				*lu_memjoin(const void *mem1, size_t size1,\
					const void *mem2, size_t size2);

char				*lu_strdup(char const *s1);
int					lu_atoi(const char *str);
void				lu_putstr(char const *s);
void				lu_putendl(char const *s);
void				lu_putnbr(int n);
void				lu_putstrstr(char const *format, char const *str);
int					lu_strcmp(char const *s1, char const *s2);

void				lu_putstr_fd(char const *s, int fd);
void				lu_putendl_fd(char const *s, int fd);
void				lu_putstrstr_fd(char const *format, char const *str,\
					int fd);
void				lu_putnbr_fd(int n, int fd);

size_t				lu_strlen(char const *s);
void				lu_lstdel(t_unit **alst);
size_t				lu_lstlen(t_unit const *alst);
t_unit				*lu_lstaddend(t_unit **lst, t_unit *new);

#endif
