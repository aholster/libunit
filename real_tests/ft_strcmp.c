/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/31 13:38:11 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/04/21 20:39:44 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *c1;
	unsigned char *c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (*c1 != '\0' && *c2 != '\0')
	{
		if (*c1 == *c2)
		{
			c1++;
			c2++;
		}
		else
			return (*c1 - *c2);
	}
	if (*c1 == '\0' || *c2 == '\0')
		return (*c1 - *c2);
	return (0);
}
