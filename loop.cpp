/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 22:29:38 by jvisser        #+#    #+#                */
/*   Updated: 2020/03/08 15:00:34 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

#include <ncurses.h>

#include "main.h"

// State function prototypes.
enum state mainMenuState();

// Function table that corresponds with the enum state
// that is declared in main.h
typedef enum state(*stateFunction)();
stateFunction	stateFunctions[] = {
  mainMenuState,
};

// Main loop of the program.
void loop(Program *const program) {
  enum state nextState;

  while (program->getState() != stopped)
  {
    // Executes current state function and waits on next state.
    nextState = stateFunctions[program->getState()]();

    // Next state will be added on top of the state stack.
    // Unless the state is 'back', in that case the top state will be removed.
    if (nextState == back) {
      program->delState();
    } else {
      program->setState(nextState);
    }

    refresh();
  }
}
