/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   curses_menu.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/08 19:41:36 by jvisser        #+#    #+#                */
/*   Updated: 2020/03/12 18:44:59 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_CURSES_MENU_H_
# define COMMON_CURSES_MENU_H_

# include <menu.h>
# include <ncurses.h>

# include <vector>
# include <utility>

# include "point.h"

// Class to represent a menu.
class CursesMenu {
 public:
  // Extractors.
  WINDOW *GetMenuWin() {return menuWin;}
  int GetPosX() {return pos.GetX();}
  int GetPosY() {return pos.GetY();}
  Point GetPos() {return pos;}
  int GetDimX() {return dim.GetX();}
  int GetDimY() {return dim.GetY();}
  Point GetDim() {return dim;}
  int GetOption() {return option;}
  bool GetCentered() {return cntrd;}
  // TODO Make private when possible. After implementation of items
  int GetIDimX() {return idim.GetX();}
  int GetIDimY() {return idim.GetY();}
  Point GetIDim() {return idim;}

  // Assigners.
  void SetPosX(const int x) {pos.SetX(x);}
  void SetPosY(const int y) {pos.SetY(y);}
  void SetPosXY(const int x, const int y) {SetPosX(x); SetPosY(y);}
  void SetPosXY(Point point) {SetPosX(point.GetX()); SetPosY(point.GetY());}
  void SetDimX(const int x) {dim.SetX(x);}
  void SetDimY(const int y) {dim.SetY(y);}
  void SetDimXY(const int x, const int y) {SetDimX(x); SetDimY(y);}
  void SetDimXY(Point point) {SetDimX(point.GetX()); SetDimY(point.GetY());}
  void SetOption(const int n) {option = n;}
  void SetCentered(const bool centered) {cntrd = centered;}
  void ToggleCentered() {cntrd = !cntrd;}

  // Window managers.
  void DrawMenu();
  void CreateMenu();
  void RedrawMenu();
  void DestroyMenu();

  // Option managers.
  void IncOption();
  void DecOption();

  // Constructor will initialize a new window pointer.
  CursesMenu(const int nOptions = 0, const std::pair<const char*, const char*>optionList[] = NULL);
 private:
  // Window pointer.
  WINDOW *menuWin;
  // Parent window for relational positioning.
  WINDOW *parent; // TODO implement functions to handle parent. Currently has stdscr as standard parent.
  // Menu pointer.
  MENU *menu;
  // Menu Items.
  int nItems;
  ITEM **items;
  // Point classes to hold position and dimension of window.
  // Ipos and idim represent internal interpresentations of attemted values.
	Point pos, dim, ipos, idim;
  // Currently selected option is represented as index.
	int	option;
  // Inidicates if window is centered
  bool cntrd;

  // Extractors.
  int GetIPosX() {return ipos.GetX();}
  int GetIPosY() {return ipos.GetY();}
  Point GetIPos() {return ipos;}

  // Assigners.
  void SetIPosX(const int x) {ipos.SetX(x);}
  void SetIPosY(const int y) {ipos.SetY(y);}
  void SetIPosXY(const int x, const int y) {SetIPosX(x); SetIPosY(y);}
  void SetIPosXY(Point point) {SetIPosX(point.GetX()); SetIPosY(point.GetY());}
  void SetIDimX(const int x) {idim.SetX(x);}
  void SetIDimY(const int y) {idim.SetY(y);}
  void SetIDimXY(const int x, const int y) {SetIDimX(x); SetIDimY(y);}
  void SetIDimXY(Point point) {SetIDimX(point.GetX()); SetIDimY(point.GetY());} 

  // Window manager functions.
  void ResizeWindow();
  void MoveWindow();
  void CenterWindow();
  void SetWindowPos();
  void SetWindowDim();
};
// TODO implement boxing feature so that offscreen doesnt get boxed.
#endif
