/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   02_writing_test.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 16:54:19 by aholster       #+#    #+#                */
/*   Updated: 2019/04/30 19:46:57 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	basic_writing(void)
{
	char	*output;
	size_t	readsize;
	int		pipe[2];

	if (pipe(pipe) == -1)
		ft_error("pipe failure");
	if (close(1) == -1)
		ft_error("failed to close stdin");
	if (dup2(pipe[1], 1) == -1)
		ft_error("failed to reroute fd");
	func();
	output = (char *)malloc(sizeof(char) * readsize + 1);
	if (output == NULL)
		ft_error("malloc failed");
	read();

	if (output == expected)
		return (0);
	else
		return (-1);
}
