/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libunit.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 15:51:10 by aholster       #+#    #+#                */
/*   Updated: 2019/04/25 14:04:00 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# define TIMEOUT 3

# define TRUE 1
# define FALSE 0

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

# include <sys/wait.h>
# include <sys/errno.h>

typedef	struct		s_unit
{
	char			*name;
	int				(*test)(void);

	struct s_unit	*next;
}					t_unit;

enum				e_funcres {ok = 1, ko = 0, segv = -1, buse = -2,\
	timeout = -3, unexpect = -4};

void				ft_error(void);
void				init_test(t_unit **lst, char *name, int (*f)(void));
int					executioner(int	(*test)(void));
int					start_test(t_unit **lst, char *test);

void				lu_putstr(char const *s);
void				lu_putendl(char const *s);
size_t				lu_strlen(char const *s);
void				lu_lstdel(t_unit **alst);
t_unit				*lu_lstaddend(t_unit **lst, t_unit *new);
void				lu_putnbr(int n);
void				lu_putstrstr(char *format, char *str);

#endif
