/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 22:29:38 by jvisser        #+#    #+#                */
/*   Updated: 2020/02/21 19:24:19 by jvisser       ########   odam.nl         */
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
	while (program->getState() != stopped)
	{
		stateFunctions[program->getState()]();
		refresh();
	}
}
