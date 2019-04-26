/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   activate_launchers.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 18:11:47 by aholster       #+#    #+#                */
/*   Updated: 2019/04/26 19:13:26 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

//π π π π π π π φφφφ ±±±± ║─┼─║ ██↑ ╦╦╦ ╤╤╤╤ ╦╦╦╦ ╠╠╠ ╩╩╩╩╩ ╣╣╣╣ ¥¥¥ ∩∩∩∩∩ │││││ ╬╬╬╬ ┴┴┴ ▌▌▌▌

static void	waterprint(void)
{
	lu_putstr("\033[0;34m~~~~~~~~~~~~~~~~~~");
	lu_putendl("\033[0;00m/∩==============∩\\\033[0;34m~~~~~~~~~~~~~~~~~~");
	lu_putstr("\033[0;34m~~~~~~~~~~~~~~~~~");
	lu_putendl("\033[0;00m/∩================∩\\\033[0;34m~~~~~~~~~~~~~~~~~");
	lu_putstr("\033[0;34m~~~~~~~~~~~~~~~~");
	lu_putendl("\033[0;00m/∩==================∩\\\033[0;34m~~~~~~~~~~~~~~~~");
}

static void	startupheader(void)
{
	lu_putendl("\x1b[38;2;197;147;124m                   /\\            /\\");
	lu_putendl("                  ╦╤╤╦          ╦╤╤╦    ");
	lu_putendl("                  ║[]║          ║[]║    ");
	lu_putendl("                  ║[]║ ± ±  ± ± ║[]║    ");
	lu_putendl("                  ║[]╠╦╤╤╦╤╤╦╤╤╦╣[]║    ");
	lu_putendl("                  ║[]║│∩∩/  \\∩∩│║[]║    ");
	lu_putendl("                  ║[]║┴/      \\┴║[]║    ");
	lu_putendl("                  ║[]║          ║[]║    ");
	lu_putendl("              _ _ ║[]║          ║[]║ _ _");
	lu_putendl("              ╦╤╦╤╬╤╦║          ║╦╤╬╤╦╤╦       ");
	lu_putendl("╦╤╦╤╦╤╦       ║─┼─┼─║║          ║║─┼─┼─║       ╦╤╦╤╦╤╦");
	lu_putendl("║─┼─┼─║       ║Ω│Ω│Ω║║          ║║Ω│Ω│Ω║       ║─┼─┼─║");
	lu_putendl("║Ω│Ω│Ω║       ║φ│¥│φ║║          ║║φ│¥│φ║       ║Ω│Ω│Ω║");
	lu_putendl("║φ│¥│φ║       ║─┼─┼─║║          ║║─┼─┼─║       ║φ│¥│φ║");
	lu_putendl("║─┼─┼─║       ║↑│↑│↑║║ \033[3;35mCelestia\x1b[38;2;206;145;120m ║║↑│↑│↑║       ║─┼─┼─║");
	lu_putendl("║↑│↑│↑║       ║│││││║║          ║║│││││║       ║↑│↑│↑║");
	lu_putendl("║│││││║█▄█▄█▄█║│││││║║          ║║│││││║█▄█▄█▄█║│││││║");
	lu_putendl("║│││││║▌ ▌ ▌ ▌║│││││║║∩========∩║║│││││║▐ ▐ ▐ ▐║│││││║");
	lu_putendl("║│││││║▌ ▌ ▌ ▌║│││││║/∩========∩\\║│││││║▐ ▐ ▐ ▐║│││││║");
	lu_putendl("╦╤╦╤╦╤╦╤╦╤╦╤╦╤╦╤╦╤╦╤/∩==========∩\\╤╦╤╦╤╦╤╦╤╦╤╦╤╦╤╦╤╦╤╦");
	lu_putendl("║∩║∩║∩║∩║∩║∩║∩║∩║∩║/∩============∩\\║∩║∩║∩║∩║∩║∩║∩║∩║∩║");
	waterprint();
}

static void	shutdownender(void)
{
	lu_putstr("π π π π π π π φφφφ ±±±± ║─┼─║ ██↑ ╦╦╦ ╤╤╤╤ ╦╦╦╦ ╠╠╠ ╩╩╩╩╩ ╣╣╣╣ ¥¥¥ ∩∩∩∩∩ │││││ ╬╬╬╬ ┴┴┴ ▌▌▌▌");
}

void		numberedlauncher(t_unit **alst, int argc, char **argv)
{
	int	current;
	int	counter;
	int	argsproc;

	current = -2;
	counter = 0;
	argsproc = 0;
	while (argsproc < argc)
	{
		current = lu_atoi(argv[argsproc]);
		while ((*alst) != NULL && counter < current)
		{
			counter++;
			(*alst) = (*alst)->next;
		}
		if (*alst == NULL || counter != current)
			return ;
		(*alst)->test();
		argsproc++;
	}
}

//	char	*castle;
//	ssize_t	status;
//	int		fd;
	// castle = (char *)malloc(sizeof(char) * CASTLE + 1);
	// if (castle == NULL)
	// 	ft_error("failed to create castle");
	// fd = open("./../framework/assets/castle", O_RDONLY);
	// if (fd == -1)
	// 	ft_error("failed to open castle");
	// status = read(fd, castle, CASTLE);
	// if (status <= 0)
	// 	ft_error("failed to see castle");
	// castle[status] = '\0';
	// lu_putstr(castle);

void		activate_launchers(t_unit **alst, int argc, char **argv)
{
	startupheader();
	if (argc > 1)
		numberedlauncher(alst, argc - 1, &argv[1]);
	else
		while ((*alst) != NULL)
		{
			(*alst)->test();
			(*alst) = (*alst)->next;
		}
	lu_lstdel(alst);
	shutdownender();
}
