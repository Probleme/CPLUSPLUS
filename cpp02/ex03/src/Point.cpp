/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 03:06:54 by ataouaf           #+#    #+#             */
/*   Updated: 2023/11/19 05:26:09 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
#include "../inc/Point.hpp"

Point::Point() : _x(0), _y(0){}

Point::Point(const Point& other) : _x(other._x), _y(other._y){}

Point& Point::operator=(const Point& other){
    (void)other;
    return *this;
}

Point::~Point(){}

Point::Point(const float x, const float y) : _x(x), _y(y){}

Fixed Point::getX() const{
    return _x;
}

Fixed Point::getY() const{
    return _y;
}