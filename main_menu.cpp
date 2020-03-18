/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_menu.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 18:33:11 by jvisser        #+#    #+#                */
/*   Updated: 2020/03/17 18:29:34 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main_menu.h"

#include <ncurses.h>

#include <vector>
#include <utility>
#include <cstring>

#include "common/point.h"
#include "common/curses_menu.h"

#include "main.h"

// List of options presented in the main menu.
const std::pair<const char*, const char*>optionList[] = {
  std::make_pair("1. ", "Exit"),
  std::make_pair("2. ", "Exit"),
  std::make_pair("3. ", "Exit"),
  std::make_pair("4. ", "Exit"),
  std::make_pair("5. ", "Exit")
};

// Corresponding return values for all presented options.
const enum state stateList[TOTAL_OPTIONS] = {
  back,
  back,
  back,
  back,
  back
};

// Prints the title in the current menu box.
void MainMenu::SetTitle() {
  WINDOW *const menu = GetMenuWin();
  const int dimX = GetDimX();
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
  WINDOW *const menu = GetMenuWin();
  const int dimY = GetIDimY();
  const int dimX = GetIDimX();
  const int option = GetOption();

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
		mvwprintw(menu, i + 2, 1, "%.*s", dimX - 2, optionList[i].second);
	}
	wattroff(menu, A_STANDOUT);

	// Print 'more' symbol at the bottom of the menu box.
  // Prints the currently selected option if it falls outside the menu box.
	if (printMore == true) {
		if (option < totalOptions) {
			mvwprintw(menu, dimY - 2, 1, "%.*s", dimX - 2, "-> ...");
		} else {
			wattron(menu, A_STANDOUT);
			mvwprintw(menu, dimY - 2, 1, "%.*s", dimX - 2, optionList[option].second);			
			wattroff(menu, A_STANDOUT);
		}
	}
}

// Fills the menu box with title and option list if there is space available.
void MainMenu::SetMenuInfo() {
  const int dimY = GetIDimY();

  if (dimY > 2) {
    SetTitle();
    if (dimY > 3) {
      SetOptions();
    }
  }
}

// Gets the state that corresponds with the currently selected option.
enum state MainMenu::GetState() {
  return (stateList[GetOption()]);
}

// Constructor hides cursor, creates window and draws the menu.
MainMenu::MainMenu() {
  // DrawMenu();
}

// Executes function based on what key was pressed.
static void HandleKey(CursesMenu *const mainMenu, const int c) {
  // Option management is done with number and arrow keys.
  if (c >= '1' && c <= '0' + TOTAL_OPTIONS) {
    mainMenu->SetOption(c - '0' - 1);
  } else if (c == KEY_UP) {
    if (mainMenu->GetOption() > 0)
      mainMenu->DecOption();
  } else if (c == KEY_DOWN) {
    if (mainMenu->GetOption() < TOTAL_OPTIONS - 1)
      mainMenu->IncOption();
  } else if (c == KEY_RESIZE) {
    mainMenu->RedrawMenu();
  }
} // TODO Add back in

// Initializes and handles the main menu.
enum state mainMenuState()
{
  int c;
  CursesMenu main_menu(TOTAL_OPTIONS, optionList);
  // MainMenu mainMenu;

  main_menu.SetCentered(true);
  main_menu.SetDimXY(MENU_X, MENU_Y);
  main_menu.DrawMenu();
  while (true) {
    //// Draws outline of menu on screen and fills menu info.
    //// mainMenu.SetMenuInfo();
    // Refreshes main and current screen.
    refresh();
    wrefresh(main_menu.GetMenuWin());

    // Wait for the next key input.
    // Returns the corresponding state on selection of the option.
    c = wgetch(main_menu.GetMenuWin());
    if (c == '\n') {  // Enter.
      return (back); // TODO Change
    } else {
      HandleKey(&main_menu, c);
		}
  }
  return (stopped);
}
