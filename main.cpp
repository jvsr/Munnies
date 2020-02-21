/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 20:49:05 by jvisser        #+#    #+#                */
/*   Updated: 2020/02/21 17:38:02 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

#include "main.h"
#include "init.h"
#include "loop.h"

int		main(void)
{
	Program program;

	init();
	loop(&program);
	endwin();
    return (0);
}
