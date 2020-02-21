/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 17:18:53 by jvisser        #+#    #+#                */
/*   Updated: 2020/02/21 17:37:56 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

enum state
{
	mainMenu,
	stopped
};

class Program
{
private:
    enum state curState;
public:
    enum state getState() {return curState;}
    void setState(enum state newState) {curState = newState;};
    Program() : curState(mainMenu) {};
};

#endif
