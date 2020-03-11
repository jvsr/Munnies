/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_menu.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 22:51:11 by jvisser        #+#    #+#                */
/*   Updated: 2020/03/11 16:00:31 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_MENU_H
# define MAIN_MENU_H

# include "common/curses_menu.h"

# include "main.h"

# define TITLE "Munnies"
# define TOTAL_OPTIONS 5
# define MENU_X 40
# define MENU_Y TOTAL_OPTIONS + 3

// Class to represent the main menu.
class MainMenu: public CursesMenu {
 public:
  // Extractors
  enum state GetState();

  // Window handlers.
  void SetMenuInfo();
  // Constructor.
  MainMenu();
 private:
  // Window handlers.
  void SetTitle();
  void SetOptions();
};

#endif
