/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 22:29:38 by jvisser        #+#    #+#                */
/*   Updated: 2020/02/20 23:48:55 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

#include "loop.h"

enum	state
{
	mainMenu,
	stopped
};

void	loop()
{
	enum state	curState = mainMenu;

	while (curState != stopped)
	{
		refresh();
	}
}
