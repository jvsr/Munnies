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

// Constructor will initialize a new window pointer.
Menu::Menu() {
  menu = newwin(0, 0, 0, 0);
}
