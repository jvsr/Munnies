/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   point.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 11:44:40 by jvisser        #+#    #+#                */
/*   Updated: 2020/02/21 12:07:36 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

class Point
{
private:
	int x, y;
public:
	int GetX() {return x;}
	int GetY() {return y;}
	void SetX(int a) {x = a;}
	void SetY(int b) {y = b;}
	Point() : x(0), y(0) {};
	Point(int a, int b) : x(a), y(b) {};
};

#endif
