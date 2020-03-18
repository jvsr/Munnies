/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   curses_menu.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 13:57:09 by jvisser        #+#    #+#                */
/*   Updated: 2020/03/12 19:11:59 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "curses_menu.h"

#include <stdlib.h>
#include <ncurses.h>

#include <string>
#include <vector>
#include <utility>

// Increases the currently selected option and moves there.
void CursesMenu::IncOption() {
  SetOption(option + 1);
  menu_driver(menu, REQ_DOWN_ITEM);
}

// Decreases the currently selected option and moves there.
void CursesMenu::DecOption() {
  SetOption(option - 1);
  menu_driver(menu, REQ_UP_ITEM);
}

// Centers the window position on the stdscr.
// If the window would be OOB, places window in the topleft corner instead.
void CursesMenu::CenterWindow() {
	const int parentX = getmaxx(parent) / 2 - GetDimX() / 2;
	const int parentY = getmaxy(parent) / 2 - GetDimY() / 2;

	SetIPosX(parentX < 0 ? 0 : parentX);
	SetIPosY(parentY < 0 ? 0 : parentY);
}

// Sets the internal representation of window position depending on screen size
// and attempted position.
void CursesMenu::SetWindowPos() {
	SetIPosXY(GetPos());
}

// Sets the internal representation of window dimensions depending on screen
// size and position. If the parent is smaller than attempted dimensions,
// it takes on the size of parent.
void CursesMenu::SetWindowDim() {
  const int parentX = getmaxx(parent);
  const int parentY = getmaxy(parent);
  const int dimX = GetDimX();
  const int dimY = GetDimY();
  const int iposX = GetIPosX();
  const int iposY = GetIPosY();

  SetIDimX(iposX + dimX > parentX ? dimX - (dimX + iposX - parentX) : dimX);
  SetIDimY(iposY + dimY > parentY ? dimY - (dimY + iposY - parentY) : dimY);
}

}

// Resizes the window with the current window dimensions.
void CursesMenu::ResizeWindow() {
  wresize(GetMenuWin(), GetIDimY(), GetIDimX());
}

// Moves the window to the current window position.
void CursesMenu::MoveWindow() {
  mvwin(GetMenuWin(), GetIPosY(), GetIPosX());
}

// Clears, repositions, resizes, redraws and posts the window
void CursesMenu::DrawMenu() {
  // werase(menuWin);
  if (cntrd == true) {
    CenterWindow();
  } else {
    SetWindowPos();
  }
  SetWindowDim();
  ResizeWindow();
  MoveWindow();
  // Creates a box around the edges of the menu window.
  box(menuWin, 0, 0);
  // Sets the menu window and subwindow to the earlier created window.
  set_menu_win(menu, menuWin);
  set_menu_sub(menu, derwin(menuWin, 6, 38, 1, 1));
  post_menu(menu);
} // TODO don't redraw on every refresh

// Creates menu items and its pointer.
void CursesMenu::CreateMenu() {
  menu = new_menu(items);
}

// Destroys menu and its items.
void CursesMenu::DestroyMenu() {
  unpost_menu(menu);
  free_menu(menu);
  for (int i = 0; i < nItems; i++) {
    free_item(items[i]);
  }
}

// Unposts menu and redraws.
void CursesMenu::RedrawMenu() {
  clear();
  unpost_menu(menu);
  DrawMenu();
}

// Constructor will initialize a new menu window and items.
CursesMenu::CursesMenu(const int nOptions, const std::pair<const char*, const char*>optionList[]) {
  curs_set(0);  // Hide cursor.
  option = 0;
  menuWin = newwin(0, 0, 0, 0);
  keypad(menuWin, true);  // Turn on keypad for menu window.
  parent = stdscr;
  cntrd = false;

  // Allocates and initializes items.
  nItems = nOptions;
  items = (ITEM**)calloc(nItems + 1, sizeof(ITEM*));
  for (int i = 0; i < nItems; i++) {
    items[i] = new_item(optionList[i].first, optionList[i].second);
  }
  items[nItems + 1] = NULL;

  // Creates new curses menu from items.
  menu = new_menu(items);
  // Removes prefix from items.
  set_menu_mark(menu, "");
}
// TODO Add option for title.
// TODO Add sizing of submenu.
