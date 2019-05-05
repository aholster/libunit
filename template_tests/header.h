/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   header.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 16:26:05 by dsaripap       #+#    #+#                */
/*   Updated: 2019/05/05 18:06:37 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libunit.h"

# define READSIZE 6
/*
**	make sure readsize is a sufficiently large number
**	if you get read_errors, try changing READSIZE
**
**	fill in necesary includes and prototypes for tests bellow this line
*/

//# include "project_here.h"

# pragma mark prototypes

int	genericide(void);
int	basic_return(void);
int	basic_writing(void);
int	advanced_writing(void);
int	advanced_clean_writing(void);
int	main(void);

#endif
