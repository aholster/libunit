/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   header.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 16:26:05 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/04/21 20:26:38 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <string.h>
# include "../framework/libunit.h"

int		atoi_positive_test();
int		atoi_doublesign_test();
int		atoi_minus_test();
int		ft_atoi(const char *str);
int		atoi_launcher(void);

int		d_isalpha_test();
int		one_isalpha_test();
int		dollar_isalpha_test();
int		ft_isalpha(int c);
int		isalpha_launcher(void);

int		six_isdigit_test(void);
int		w_isdigit_test(void);
int		four_isdigit_test(void);
int		ft_isdigit(int c);
int		isdigit_launcher(void);

int		diff_strcmp_test(void);
int		same_strcmp_test(void);
int		empty_strcmp_test(void);
int		ft_strcmp(const char *s1, const char *s2);
int		strcmp_launcher(void);

int		barcelona_strlen_test(void);
int		aristotle_strlen_test(void);
int		strlen_test03(void);
size_t	ft_strlen(const char *s);
int		strlen_launcher(void);

#endif
