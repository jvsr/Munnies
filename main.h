/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 17:18:53 by jvisser        #+#    #+#                */
/*   Updated: 2020/03/02 17:31:48 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <vector>

enum state
{
	mainMenu,
    back,
	stopped
};

class Program
{
private:
    std::vector<enum state> curState;
public:
    enum state getState() {return curState.front();}
    void setState(const enum state newState) {curState.insert(curState.begin(), newState);};
    void delState() {curState.erase(curState.begin());};
    Program();
};

#endif
