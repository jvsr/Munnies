/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 20:49:05 by jvisser        #+#    #+#                */
/*   Updated: 2020/03/08 17:38:52 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

#include <ncurses.h>

#include "init.h"
#include "loop.h"

// Constructor pushed the stopped and mainMenu state as the first two
// on the state stack.
Program::Program() {
  curState.insert(curState.begin(), stopped);
  curState.insert(curState.begin(), mainMenu);
}

int main() {
  Program program;

  init();
  loop(&program);
  endwin();
  return (0);
}
