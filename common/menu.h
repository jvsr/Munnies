/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   menu.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/08 19:41:36 by jvisser        #+#    #+#                */
/*   Updated: 2020/03/08 19:51:40 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_MENU_H_
# define COMMON_MENU_H_

# include "point.h"

#include <ncurses.h>

// Class to represent a menu.
class Menu {
 public:
  // Extractors.
  WINDOW *GetMenu() {return menu;}
  int GetPosX() {return pos.GetX();}
  int GetPosY() {return pos.GetY();}
  Point GetPos() {return pos;}
  int GetDimX() {return dim.GetX();}
  int GetDimY() {return dim.GetY();}
  Point GetDim() {return dim;}
  int GetOption() {return option;}

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

  // Option managers.
  void IncOption();
  void DecOption();

  // Constructor will initialize a new window pointer.
  Menu();
 private:
  // Window pointer.
  WINDOW *menu;
  // Point classes to hold position and dimension of window.
	Point pos, dim;
  // Currently selected option is represented as index.
	int	option;
};

#endif
