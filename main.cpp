/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 20:49:05 by jvisser        #+#    #+#                */
/*   Updated: 2020/02/21 19:18:46 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

#include "main.h"
#include "init.h"
#include "loop.h"

int		main()
{
	Program program;

	init();
	loop(&program);
	endwin();
    return (0);
}
