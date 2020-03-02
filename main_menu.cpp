/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_menu.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 22:29:00 by jvisser        #+#    #+#                */
/*   Updated: 2020/03/02 17:55:11 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <ncurses.h>

#include "common/point.h"

#include "main.h"
#include "main_menu.h"

const char	optionList[TOTAL_OPTIONS][MENU_X - 1] = {
	"-> 1. Exit                            ",
	"-> 2. Exit                            ",
	"-> 3. Exit                            ",
	"-> 4. Exit                            ",
	"-> 5. Exit                            "
};

const enum state	stateList[TOTAL_OPTIONS] = {
	back,
	back,
	back,
	back,
	back
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
	const int dimX = dim.GetX();
	const int s =  dimX / 2 - strlen(TITLE) / 2;
	const int start = s > 1 ? s : 1;

	wattron(menu, A_BOLD | A_UNDERLINE);
	mvwprintw(menu, 1, start, "%.*s", dimX - 2, TITLE);
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
	// Print 'more' symbol or selected option if not all options fit in box
	if (printMore == true) {
		if (option < nOptions) {
			mvwprintw(menu, dimY - 2, 1, "%.*s", dimX - 2, "-> ...");
		} else {
			wattron(menu, A_STANDOUT);
			mvwprintw(menu, dimY - 2, 1, "%.*s", dimX - 2, optionList[option]);			
			wattroff(menu, A_STANDOUT);
		}
	}
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
void	MainMenu::SetOption(const int n)
{
	if (n >= 1 && n <= TOTAL_OPTIONS) {
		option = n - 1;
	}
}

enum state	MainMenu::GetState()
{
	return (stateList[option]);
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

static void	handleKey(MainMenu *const mainMenu, const int c)
{
	if (c >= '1' && c <= '0' + TOTAL_OPTIONS) {
		mainMenu->SetOption(c - '0');
	} else if (c == KEY_UP) {
		mainMenu->DecOption();
	} else if (c == KEY_DOWN) {
		mainMenu->IncOption();
	} else if (c == KEY_RESIZE) {
		resizeterm(getmaxy(stdscr), getmaxx(stdscr));
	}
	mainMenu->DrawMenu();
}

enum state	mainMenuState()
{
    int c;
    MainMenu mainMenu;

	while (true) {
    	refresh();
	    wrefresh(mainMenu.menu);
        c = getch();
		if (c == '\n') {
			return (mainMenu.GetState());
		} else {
			handleKey(&mainMenu, c);
		}
    }
    return (stopped);
}
