/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_menu.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 22:51:11 by jvisser        #+#    #+#                */
/*   Updated: 2020/02/21 00:14:43 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_MENU_H
# define MAIN_MENU_H

# include <cstring>
# include <ncurses.h>

# define TITLE "Munnies"
# define MENU_X 40
# define MENU_Y 8
# define N_OPTIONS 2

const char	optionList[N_OPTIONS][MENU_X - 1] = {
	"-> 1. Foo                             ",
	"-> 2. Bar                             "
};

class	MainMenu
{
private:
	int x, y, posx, posy;
	int	option;
public:
	WINDOW  *menu;
	void    SetWindowPos();
	void    SetMenuInfo();
	void    SetOption(int n);
	void    DrawMenu();
	MainMenu();
};

void	MainMenu::SetWindowPos()
{
	posx = COLS / 2 - x / 2;
	if (posx < 0)
		posx = 0;
	posy = LINES / 2 - y / 2;
	if (posy < 0)
		posy = 0;
}

void	MainMenu::SetMenuInfo()
{
	wattron(menu, A_BOLD | A_UNDERLINE);
	mvwprintw(menu, 1, x / 2 - strlen(TITLE) / 2, TITLE);
	wattroff(menu, A_BOLD | A_UNDERLINE);
	for (int i = 0; i < N_OPTIONS; i++) {
		if (i == option)
			wattron(menu, A_STANDOUT);
		else
			wattroff(menu, A_STANDOUT);
		mvwprintw(menu, i + 2, 1, optionList[i]);
	}
	wattroff(menu, A_STANDOUT);
}

void	MainMenu::SetOption(int n)
{
	option = n - 1;
	SetMenuInfo();
}

void	MainMenu::DrawMenu()
{
	clear();
	box(menu, 0, 0);
	SetMenuInfo();
}

MainMenu::MainMenu()
{
	curs_set(0);	// Hide cursor
	x = MENU_X;
	y = MENU_Y;
	SetWindowPos();
	menu = newwin(y, x, posy, posx);
	option = 0;
	DrawMenu();
}

#endif
