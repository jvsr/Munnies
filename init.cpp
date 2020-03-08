/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 22:55:18 by jvisser        #+#    #+#                */
/*   Updated: 2020/03/08 14:55:59 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

#include <ncurses.h>

#include <iostream>

static void initColor() {
	start_color();

  // End program if terminal does not support colors.
	if (has_colors() == FALSE) {
		endwin();
		std::cout << "Terminal does not support color\n";
		exit(EXIT_FAILURE);
	}

	// Initialize standard color pairs.
	init_pair(1, COLOR_WHITE, COLOR_BLUE);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
}

void init()
{
  initscr();
  initColor();
  cbreak();  // Disables buffering of typed characters.
  noecho();  // Disables echo of typed characters.
  keypad(stdscr, TRUE);  // Enables special keys.
}
