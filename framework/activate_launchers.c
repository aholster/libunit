/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   activate_launchers.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 18:11:47 by aholster       #+#    #+#                */
/*   Updated: 2019/05/03 16:09:52 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

//π π π π π π π φφφφ ±±±± ║─┼─║ ██↑ ╦╦╦ ╤╤╤╤ ╦╦╦╦ ╠╠╠ ╩╩╩╩╩ ╣╣╣╣ ¥¥¥ ∩∩∩∩∩ │││││ ╬╬╬╬ ┴┴┴ ▌▌▌▌

static void		waterprint(void)
{
	lu_putstr("╦╤╦╤╦╤╦╤╦╤╦╤╦╤╦╤╦╤╦╤\033[0;00m/∩==========∩\\");
	lu_putendl("\x1b[38;2;197;147;124m╤╦╤╦╤╦╤╦╤╦╤╦╤╦╤╦╤╦╤╦");
	lu_putstr("║∩║∩║∩║∩║∩║∩║∩║∩║∩║\033[0;00m/∩============∩\\");
	lu_putendl("\x1b[38;2;197;147;124m║∩║∩║∩║∩║∩║∩║∩║∩║∩║\033[0;00m");
	lu_putstr("\033[0;34m~~~~~~~~~~~~~~~~~~");
	lu_putendl("\033[0;00m/∩==============∩\\\033[0;34m~~~~~~~~~~~~~~~~~~");
	lu_putstr("\033[0;34m~~~~~~~~~~~~~~~~~");
	lu_putendl("\033[0;00m/∩================∩\\\033[0;34m~~~~~~~~~~~~~~~~~");
	lu_putstr("\033[0;34m~~~~~~~~~~~~~~~~");
	lu_putendl("\033[0;00m/∩==================∩\\\033[0;34m~~~~~~~~~~~~~~~~");
}

static void		startupheader(void)
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
	lu_putstr("║─┼─┼─║       ║↑│↑│↑║║ \033[3;35mCelestia");
	lu_putendl("\x1b[38;2;206;145;120m ║║↑│↑│↑║       ║─┼─┼─║");
	lu_putendl("║↑│↑│↑║       ║│││││║║          ║║│││││║       ║↑│↑│↑║");
	lu_putendl("║│││││║█▄█▄█▄█║│││││║║          ║║│││││║█▄█▄█▄█║│││││║");
	lu_putstr("║│││││║▌ ▌ ▌ ▌║│││││║║\033[0;00m∩========∩");
	lu_putendl("\x1b[38;2;197;147;124m║║│││││║▐ ▐ ▐ ▐║│││││║");
	lu_putstr("║│││││║▌ ▌ ▌ ▌║│││││║\033[0;00m/∩========∩\\");
	lu_putendl("\x1b[38;2;197;147;124m║│││││║▐ ▐ ▐ ▐║│││││║");
	waterprint();
}

static void		shutdownender(void)
{
	lu_putendl("              ╦╤╦╤╦╤╦            ╦╤╦╤╦╤╦              ");
	lu_putendl("╦╤╦╤╦╤╦       ║─┼─┼─║            ║─┼─┼─║       ╦╤╦╤╦╤╦");
	lu_putendl("║─┼─┼─║       ║Ω│Ω│Ω║            ║Ω│Ω│Ω║       ║─┼─┼─║");
	lu_putendl("║Ω│Ω│Ω║       ║φ│¥│φ║║          ║║φ│¥│φ║       ║Ω│Ω│Ω║");
	lu_putendl("║↑│↑│↑║       ║│││││║║          ║║│││││║       ║↑│↑│↑║");
	lu_putendl("║│││││║█▄█▄█▄█║│││││║║          ║║│││││║█▄█▄█▄█║│││││║");
}

void			activate_launchers(t_unit **alst, int argc, char **argv)
{
	t_unit	*begin;

	begin = *alst;
	startupheader();
	if (argc > 1)
		launcherparser(alst, (size_t)argc - 1, &argv[1]);
	else
		while ((*alst) != NULL)
		{
			(*alst)->test();
			(*alst) = (*alst)->next;
		}
	lu_lstdel(&begin);
	shutdownender();
}
