/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   menu.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 13:57:09 by jvisser        #+#    #+#                */
/*   Updated: 2020/03/09 13:57:09 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "menu.h"

#include <ncurses.h>

// Increases the currently selected option.
void Menu::IncOption() {
  SetOption(option + 1);
}

// Decreases the currently selected option.
void Menu::DecOption() {
  SetOption(option - 1);
}

// Constructor will initialize a new window pointer.
Menu::Menu() {
  curs_set(0);  // Hide cursor
  option = 0;
  menu = newwin(0, 0, 0, 0);
}
