/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 03:07:14 by ataouaf           #+#    #+#             */
/*   Updated: 2023/11/19 05:25:38 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point{
    private:
        Fixed const _x;
        Fixed const _y;
    public:
        Point();
        Point(const Point& other);
        Point& operator=(const Point& other);
        ~Point();
        Point(const float x, const float y);
        Fixed getX() const;
        Fixed getY() const;
};

#endif