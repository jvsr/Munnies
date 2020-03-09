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

#include <ncurses.h>

// Class to represent a menu.
class Menu {
 public:
  // Extractors
  WINDOW *GetMenu() {return menu;}

  // Constructor will initialize a new window pointer.
  Menu();
 private:
  // Window pointer.
  WINDOW *menu;
};

#endif