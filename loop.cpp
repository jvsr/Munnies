/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 22:29:38 by jvisser        #+#    #+#                */
/*   Updated: 2020/02/21 17:56:48 by jvisser       ########   odam.nl         */
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

void	loop(Program *program)
{
	while (program->getState() != stopped)
	{
		stateFunctions[program->getState()]();
		refresh();
	}
}
