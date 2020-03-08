/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_menu.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 22:51:11 by jvisser        #+#    #+#                */
/*   Updated: 2020/03/08 15:34:59 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_MENU_H
# define MAIN_MENU_H

# include <ncurses.h>

# define TITLE "Munnies"
# define TOTAL_OPTIONS 5
# define MENU_X 40
# define MENU_Y TOTAL_OPTIONS + 3

class Point;

class	MainMenu
{
private:
	// Option is represented as index.
	int	option;
	Point pos, dim;
	void    SetWindowPos();
	void    SetWindowDim();
	void    SetWindowPosDim();
	void    ResizeWindow();
	void    MoveWindow();
	void	CenterWindow();
	void    SetTitle();
	void    SetOptions();
	void    SetMenuInfo();
public:
	WINDOW  *menu;
	void    IncOption();
	void    DecOption();
	void    SetOption(const int n);
	void    DrawMenu();
	enum state	GetState();
	MainMenu();
};

#endif
