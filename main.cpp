/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 20:49:05 by jvisser        #+#    #+#                */
/*   Updated: 2020/02/20 22:59:06 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

#include "init.h"
#include "loop.h"

int		main(void)
{
	init();
	loop();
	endwin();
    return (0);
}
