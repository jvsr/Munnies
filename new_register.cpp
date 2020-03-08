/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_register.cpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/08 19:27:25 by jvisser        #+#    #+#                */
/*   Updated: 2020/03/08 19:32:34 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "new_register.h"

#include <ncurses.h>

#include "main.h"

// Creates a new register.
enum state newRegisterState()
{
  int c;

  while (true) {
    // Clears screen
    refresh();

    // Wait for the next key input.
    // Returns the corresponding state on selection of the option.
    c = getch();
    if (c == '\n') {
      return (back);
    }
  }
  return (stopped);
}
