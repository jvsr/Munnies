/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 22:29:38 by jvisser        #+#    #+#                */
/*   Updated: 2020/03/02 17:45:04 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

#include "main.h"
#include "loop.h"

enum state mainMenuState();

typedef enum state(*stateFunction)();

stateFunction	stateFunctions[] = {
	mainMenuState,
};

void	loop(Program *const program)
{
	enum state	nextState;

	while (program->getState() != stopped)
	{
		nextState = stateFunctions[program->getState()]();
		if (nextState == back) {
			program->delState();
		} else {
			program->setState(nextState);
		}
		refresh();
	}
}
