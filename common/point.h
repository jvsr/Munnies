/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   point.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 11:44:40 by jvisser        #+#    #+#                */
/*   Updated: 2020/03/08 17:13:03 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_POINT_H_
# define COMMON_POINT_H_

// Class to represent a point.
class Point {
 public:
  // Extractors.
  int GetX() {return x;}
  int GetY() {return y;}

  // Assigners.
  void SetX(int xval) {x = xval;}
  void SetY(int yval) {y = yval;}

  // Constructor uses default values to support no, one or two arguments given.
  Point(int xval = 0, int yval = 0) {
    x = xval;
    y = yval;
  };
 private:
  int x, y;
};

#endif
