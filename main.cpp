/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 20:49:05 by jvisser        #+#    #+#                */
/*   Updated: 2020/03/02 17:31:22 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

#include "main.h"
#include "init.h"
#include "loop.h"

Program::Program()
{
	curState.insert(curState.begin(), stopped);
	curState.insert(curState.begin(), mainMenu);
}

int		main()
{
	Program program;

	init();
	loop(&program);
	endwin();
    return (0);
}
