/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 03:06:26 by ataouaf           #+#    #+#             */
/*   Updated: 2023/11/19 05:41:01 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
#include "../inc/Point.hpp"

Fixed abs(Fixed const a)
{
    if (a < 0)
        return a * -1;
    return a;
}

Fixed area(Point const a, Point const b, Point const c)
{
    return abs((a.getX() * (b.getY() - c.getY())) + (b.getX() * (c.getY() - a.getY())) + (c.getX() * (a.getY() - b.getY()))) / 2;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed abc = area(a, b, c);
    Fixed abp = area(a, b, point);
    Fixed acp = area(a, c, point);
    Fixed bcp = area(b, c, point);
    if (abc == 0 || abp == 0 || acp == 0 || bcp == 0)
    {        
        std::cout << "Error: Point is on the edge of the triangle" << std::endl;
        return false;
    }
    if (abc == abp + acp + bcp)
    {
        std::cout << "Point is inside the triangle" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Point is outside the triangle" << std::endl;
        return false;
    }
}