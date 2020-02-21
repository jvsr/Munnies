/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_menu.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 22:51:11 by jvisser        #+#    #+#                */
/*   Updated: 2020/02/21 15:41:48 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_MENU_H
# define MAIN_MENU_H

# include <cstring>
# include <ncurses.h>

# include "point.h"

# define TITLE "Munnies"
# define MENU_X 40
# define TOTAL_OPTIONS 3
# define MENU_Y TOTAL_OPTIONS + 3

const char	optionList[TOTAL_OPTIONS][MENU_X - 1] = {
	"-> 1. Foo                             ",
	"-> 2. Bar                             ",
	"-> 3. Oof                             "
};

class	MainMenu
{
private:
	int	option;
	Point pos, dim;
	void    SetWindowPos();
	void    SetWindowDim();
	void    SetWindowPosDim();
	void    ResizeWindow();
	void    MoveWindow();
	void	CenterWindow();
	void    SetTitle();
	void    SetOptions();
	void    SetMenuInfo();
public:
	WINDOW  *menu;
	void    IncOption();
	void    DecOption();
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

void	MainMenu::SetTitle()
{
	wattron(menu, A_BOLD | A_UNDERLINE);
	mvwprintw(menu, 1, dim.GetX() / 2 - strlen(TITLE) / 2, TITLE);
	wattroff(menu, A_BOLD | A_UNDERLINE);
}
void	MainMenu::SetOptions()
{
	int nOptions = 0;
	bool printMore = false;
	const int dimY = dim.GetY();
	const int dimX = dim.GetX();

	// Calculate total options to be printed
	if (dimY - 3 < TOTAL_OPTIONS) {
		nOptions = dimY - 4;
		printMore = true;
	} else {
		nOptions = TOTAL_OPTIONS;
	}
	// Print options and highlight selected option
	for (int i = 0; i < nOptions; i++) {
		if (i == option)
			wattron(menu, A_STANDOUT);
		else
			wattroff(menu, A_STANDOUT);
		mvwprintw(menu, i + 2, 1, "%.*s", dimX - 2, optionList[i]);
	}
	wattroff(menu, A_STANDOUT);
	if (printMore == true)
		mvwprintw(menu, dimY - 2, 1, "%.*s", dimX - 2, "-> ...");
}
void	MainMenu::SetMenuInfo()
{
	const int dimY = dim.GetY();

	if (dimY > 2) {
		SetTitle();
		if (dimY > 3) {
			SetOptions();
		}
	}
}

void	MainMenu::IncOption()
{
	SetOption(option + 2);
}
void	MainMenu::DecOption()
{
	SetOption(option);
}
void	MainMenu::SetOption(int n)
{
	if (n >= 1 && n <= TOTAL_OPTIONS) {
		option = n - 1;
	}
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
