/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libunit.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 15:51:10 by aholster       #+#    #+#                */
/*   Updated: 2019/05/06 15:51:20 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# define TIMEOUT 6

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
	int				(*test)(void);
	t_retcode		expectation;
	struct s_unit	*next;
}					t_unit;

void				ft_error(char *error);
int					putresult(t_retcode code, t_retcode expected);
void				init_test(t_unit **lst, char *name, int (*f)(void));
void				init_advtest(t_unit **lst, char *name, \
					t_retcode expected_result, int (*f)(void));
t_retcode			executioner(int	(*test)(void));
int					start_test(t_unit **lst, char *test);

void				loadlaunch(t_unit **alst, int (*f)(void));
void				activate_launchers(t_unit **alst, int argc, char **argv);
void				launcherparser(t_unit **alst, size_t argc, char **argv);

int					lu_atoi(const char *str);
void				lu_putstr(char const *s);
void				lu_putendl(char const *s);
void				lu_putnbr(int n);
void				lu_putstrstr(char *format, char *str);

void				lu_putstr_fd(char const *s, int fd);
void				lu_putendl_fd(char const *s, int fd);
void				lu_putstrstr_fd(char *format, char *str, int fd);
void				lu_putnbr_fd(int n, int fd);

size_t				lu_strlen(char const *s);
void				lu_lstdel(t_unit **alst);
t_unit				*lu_lstaddend(t_unit **lst, t_unit *new);

#endif
