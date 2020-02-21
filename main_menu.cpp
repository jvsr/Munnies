/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_menu.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 22:29:00 by jvisser        #+#    #+#                */
/*   Updated: 2020/02/21 00:06:45 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

#include "main_menu.h"

static void handleKey(MainMenu mainMenu, int c)
{
    if (c >= '1' && c <= '0' + N_OPTIONS)
        mainMenu.SetOption(c - '0');
    else if (c == KEY_RESIZE) {
        mainMenu.SetWindowPos();
        mainMenu.DrawMenu();
    } // TODO Proper handling of LINES and COLS on resize
}

void	mainMenuState(void)
{
    int        c;
    MainMenu    mainMenu;

	while (true) {
    	refresh();
	    wrefresh(mainMenu.menu);
        c = getch();
        handleKey(mainMenu, c);
    }
}
