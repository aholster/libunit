/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   header.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 16:26:05 by dsaripap       #+#    #+#                */
/*   Updated: 2019/04/24 13:32:24 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <string.h>
# include "libunit.h"
# include "libft.h"

int		atoi_positive_test(void);
int		atoi_doublesign_test(void);
int		atoi_minus_test(void);
int		atoi_launcher(void);

int		d_isalpha_test();
int		one_isalpha_test();
int		dollar_isalpha_test();
int		isalpha_launcher(void);

int		six_isdigit_test(void);
int		w_isdigit_test(void);
int		four_isdigit_test(void);
int		isdigit_launcher(void);

int		diff_strcmp_test(void);
int		same_strcmp_test(void);
int		empty_strcmp_test(void);
int		strcmp_launcher(void);

int		barcelona_strlen_test(void);
int		aristotle_strlen_test(void);
int		strlen_test03(void);
int		strlen_launcher(void);

#endif
