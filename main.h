/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 17:18:53 by jvisser        #+#    #+#                */
/*   Updated: 2020/03/08 17:47:27 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <vector>

// All possible program states.
// Correspond with the function table, declared in loop.cpp.
enum state {
  mainMenu,
  back,
  stopped
};

class Program {
 public:
  // Extractors.
  enum state getState() {return curState.front();}

  // Assigners.
  void setState(const enum state newState) {curState.insert(curState.begin(), newState);};

  // Delete top value of the state stack.
  void delState() {curState.erase(curState.begin());};

  // Constructor.
  Program();
 private:
  // Stack of program states.
  std::vector<enum state> curState;
};

#endif
