/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_menu.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 22:29:00 by jvisser        #+#    #+#                */
/*   Updated: 2020/03/08 17:23:58 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main_menu.h"

#include <ncurses.h>

#include <cstring>

#include "common/point.h"

#include "main.h"

// List of options presented in the main menu.
const char optionList[TOTAL_OPTIONS][MENU_X - 1] = {
  "-> 1. Exit                            ",
  "-> 2. Exit                            ",
  "-> 3. Exit                            ",
  "-> 4. Exit                            ",
  "-> 5. Exit                            "
};

// Corresponding return values for all presented options.
const enum state stateList[TOTAL_OPTIONS] = {
  back,
  back,
  back,
  back,
  back
};

// Centers the window position on the stdscr.
// If the window would be OOB, places window in the topleft corner instead.
void MainMenu::SetWindowPos() {
	const int stdscrX = getmaxx(stdscr) / 2 - MENU_X / 2;
	const int stdscrY = getmaxy(stdscr) / 2 - MENU_Y / 2;

	pos.SetX(stdscrX < 0 ? 0 : stdscrX);
	pos.SetY(stdscrY < 0 ? 0 : stdscrY);
}

// Sets the window dimensions specified in defined MENU_ X and Y.
// If the stdscr is smaller than said defines, takes on the size of stdscr.
void MainMenu::SetWindowDim() {
	const int stdscrX = getmaxx(stdscr);
	const int stdscrY = getmaxy(stdscr);
	
	dim.SetX(MENU_X < stdscrX ? MENU_X : stdscrX);
	dim.SetY(MENU_Y < stdscrY ? MENU_Y : stdscrY);
}

// Sets both window position and dimensions.
void MainMenu::SetWindowPosDim() {
  SetWindowDim();
  SetWindowPos();
}

// Resizes the window with the current window dimensions.
void MainMenu::ResizeWindow() {
  wresize(menu, dim.GetY(), dim.GetX());
}

// Moves the window to the current window position.
void MainMenu::MoveWindow() {
  mvwin(menu, pos.GetY(), pos.GetX());
}

// Changes position and dimension of the window, resizes and moves the window.
void MainMenu::CenterWindow() {
  SetWindowPosDim();
  ResizeWindow();
  MoveWindow();
}

// Prints the title in the current menu box.
void MainMenu::SetTitle() {
  const int dimX = dim.GetX();
  // Attempted starting index for writing.
  const int s = dimX / 2 - strlen(TITLE) / 2;
  // If Attempted starting index is OOB, will set starting index to 1.
  const int start = s > 1 ? s : 1;

  // Title is printed in bold and underlined.
	wattron(menu, A_BOLD | A_UNDERLINE);
	mvwprintw(menu, 1, start, "%.*s", dimX - 2, TITLE);
	wattroff(menu, A_BOLD | A_UNDERLINE);
}

// Prints the options in the current menu box.
void MainMenu::SetOptions() {
  int totalOptions = 0;
  bool printMore = false;
  const int dimY = dim.GetY();
  const int dimX = dim.GetX();

	// Calculate total options to be printed.
  // If not all options will fit in the menu box, will print 'more' symbol.
  if (dimY - 3 < TOTAL_OPTIONS) {
		totalOptions = dimY - 4;
		printMore = true;
	} else {
		totalOptions = TOTAL_OPTIONS;
	}

	// Print options and highlight currently selected option.
  // Ensures that options fit in the menu box.
	for (int i = 0; i < totalOptions; i++) {
		if (i == option)
			wattron(menu, A_STANDOUT);
		else
			wattroff(menu, A_STANDOUT);
		mvwprintw(menu, i + 2, 1, "%.*s", dimX - 2, optionList[i]);
	}
	wattroff(menu, A_STANDOUT);

	// Print 'more' symbol at the bottom of the menu box.
  // Prints the currently selected option if it falls outside the menu box.
	if (printMore == true) {
		if (option < totalOptions) {
			mvwprintw(menu, dimY - 2, 1, "%.*s", dimX - 2, "-> ...");
		} else {
			wattron(menu, A_STANDOUT);
			mvwprintw(menu, dimY - 2, 1, "%.*s", dimX - 2, optionList[option]);			
			wattroff(menu, A_STANDOUT);
		}
	}
}

// Fills the menu box with title and option list if there is space available.
void MainMenu::SetMenuInfo() {
  const int dimY = dim.GetY();

  if (dimY > 2) {
    SetTitle();
    if (dimY > 3) {
      SetOptions();
    }
  }
}

// Increases the currently selected option.
void MainMenu::IncOption() {
  SetOption(option + 2);
}

// Decreases the currently selected option.
void MainMenu::DecOption() {
  SetOption(option);
}

// Sets the currently selected option to a specified option.
void MainMenu::SetOption(const int n) {
	if (n >= 1 && n <= TOTAL_OPTIONS) {
		option = n - 1;
	}
}

// Gets the state that corresponds with the currently selected option.
enum state MainMenu::GetState() {
  return (stateList[option]);
}

// Fully resets, recenters, refils and redraws the menu window.
void MainMenu::DrawMenu() {
  clear();
  wclear(menu);
  CenterWindow();
  // Creates a box around the edges of the menu window.
  box(menu, 0, 0);
  SetMenuInfo();
}

// Constructor hides cursor, creates window and draws the menu.
MainMenu::MainMenu() {
  curs_set(0);  // Hide cursor
  option = 0;
  menu = newwin(0, 0, 0, 0);
  DrawMenu();
}

// Executes function based on what key was pressed.
static void handleKey(MainMenu *const mainMenu, const int c) {
  // Option management is done with number and arrow keys.
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

// Initializes and handles the main menu.
enum state	mainMenuState()
{
  int c;
  MainMenu mainMenu;

  while (true) {
    // Clears screen
    refresh();
    wrefresh(mainMenu.menu);

    // Wait for the next key input.
    // Returns the corresponding state on selection of the option.
    c = getch();
    if (c == '\n') {
      return (mainMenu.GetState());
    } else {
      handleKey(&mainMenu, c);
		}
  }
  return (stopped);
}
