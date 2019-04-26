/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lu_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 16:31:17 by aholster       #+#    #+#                */
/*   Updated: 2019/04/26 18:58:20 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static int	ft_iswhitespace(int c)
{
	if (c == '\t' || c == '\r' || c == '\n' || c == '\f' || c == '\v'\
	|| c == ' ')
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_isstrlower(const char *str, const char *str2, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n && str[index] != '\0')
	{
		if (!(str[index] <= str2[index]))
			return (0);
		index++;
	}
	return (1);
}

static int	ft_exceptional(const char *str, const char sign)
{
	size_t	index;

	index = 0;
	while (ft_isdigit(str[index]) == 1 && index < 19)
	{
		index++;
	}
	if (index == 19 && ft_isdigit(str[index]) == 1)
	{
		if (sign == '-')
			return (0);
		return (-1);
	}
	else if (index == 19)
	{
		if (sign == '-' && ft_isstrlower(str, "9223372036854775808", 19) == 0)
			return (0);
		if (sign != '-' && ft_isstrlower(str, "9223372036854775807", 19) == 0)
			return (-1);
	}
	return (42);
}

int			lu_atoi(const char *str)
{
	size_t		i;
	long long	n;

	i = 0;
	n = 0;
	while (ft_iswhitespace(*str) == 1)
		str++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (ft_exceptional(&str[i], str[0]) != 42)
		return (ft_exceptional(&str[i], str[0]));
	while (ft_isdigit(str[i]) == 1)
	{
		n = (str[i] - '0') + n;
		if (ft_isdigit(str[i + 1]) == 1)
			n = (n * 10);
		i++;
	}
	if (str[0] == '-')
		n = -(n);
	return ((int)n);
}
