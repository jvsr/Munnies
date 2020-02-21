/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_menu.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 22:51:11 by jvisser        #+#    #+#                */
/*   Updated: 2020/02/21 14:04:46 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_MENU_H
# define MAIN_MENU_H

# include <cstring>
# include <ncurses.h>

# include "point.h"

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
	Point pos, dim;
	void    SetWindowPos();
	void    SetWindowDim();
	void    SetWindowPosDim();
	void    ResizeWindow();
	void    MoveWindow();
	void	CenterWindow();
	void    SetMenuInfo();
	int	option;
public:
	WINDOW  *menu;
	void    SetOption(int n);
	void    DrawMenu();
	MainMenu();
};

void	MainMenu::SetWindowPos()
{
	const int stdscrX = getmaxx(stdscr) / 2 - MENU_X / 2;
	const int stdscrY = getmaxy(stdscr) / 2 - MENU_Y / 2;

	pos.SetX(stdscrX >= 0 ? stdscrX : 0);
	pos.SetY(stdscrY >= 0 ? stdscrY : 0);
}
void	MainMenu::SetWindowDim()
{
	const int stdscrX = getmaxx(stdscr);
	const int stdscrY = getmaxy(stdscr);
	
	dim.SetX(MENU_X < stdscrX ? MENU_X : stdscrX);
	dim.SetY(MENU_Y < stdscrY ? MENU_Y : stdscrY);
}
void	MainMenu::SetWindowPosDim()
{
	SetWindowDim();
	SetWindowPos();
}
void	MainMenu::ResizeWindow()
{
	wresize(menu, dim.GetY(), dim.GetX());
}
void	MainMenu::MoveWindow()
{
	mvwin(menu, pos.GetY(), pos.GetX());
}
void	MainMenu::CenterWindow()
{
	SetWindowPosDim();
	ResizeWindow();
	MoveWindow();
}

void	MainMenu::SetMenuInfo()
{
	wattron(menu, A_BOLD | A_UNDERLINE);
	mvwprintw(menu, 1, dim.GetX() / 2 - strlen(TITLE) / 2, TITLE);
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
	wclear(menu);
	CenterWindow();
	box(menu, 0, 0);
	SetMenuInfo();
}

MainMenu::MainMenu()
{
	curs_set(0);	// Hide cursor
	option = 0;
	menu = newwin(0, 0, 0, 0);
	DrawMenu();
}

#endif
