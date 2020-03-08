/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_menu.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 22:51:11 by jvisser        #+#    #+#                */
/*   Updated: 2020/03/08 19:51:45 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_MENU_H
# define MAIN_MENU_H

# include "common/menu.h"
# include "common/point.h"

# include "main.h"

# define TITLE "Munnies"
# define TOTAL_OPTIONS 5
# define MENU_X 40
# define MENU_Y TOTAL_OPTIONS + 3

// Class to represent the main menu.
class MainMenu: public Menu {
 public:
  // Extractors
  enum state GetState();

  // Option managers.
  void IncOption();
  void DecOption();
  void SetOption(const int n);

  // Drawing.
  void DrawMenu();

  // Constructor.
  MainMenu();
 private:
	// Option is represented as index.
	int	option;

  // Point classes to hold position and dimension of window.
	Point pos, dim;
 
  // Window handlers.
  void SetWindowPos();
  void SetWindowDim();
  void SetWindowPosDim();
  void ResizeWindow();
  void MoveWindow();
  void CenterWindow();
  void SetTitle();
  void SetOptions();
  void SetMenuInfo();
};

#endif
