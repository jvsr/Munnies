/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 22:55:18 by jvisser        #+#    #+#                */
/*   Updated: 2020/02/20 22:57:10 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>

using namespace std;

static void	initColor()
{
	start_color();
	if (has_colors() == FALSE) {
		endwin();
		cout << "Your terminal does not support color\n";
		exit(EXIT_FAILURE);
	}	// End program if terminal does not support colors
	// Initialize standard color pairs
	init_pair(1, COLOR_WHITE, COLOR_BLUE);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
}

void		init()
{
	initscr();
	initColor();
	cbreak();				// Disables buffering of typed characters
	noecho();				// Disables echo of typed characters
	keypad(stdscr, TRUE);	// Enables special keys
}
