/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 03:06:26 by ataouaf           #+#    #+#             */
/*   Updated: 2023/11/17 03:48:13 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
#include "../inc/Point.hpp"

float area(Point const a, Point const b, Point const c)
{
    return abs((a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2.0);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float abc = area(a, b, c);
    float abp = area(a, b, point);
    float acp = area(a, c, point);
    float bcp = area(b, c, point);
    if (!abc || !abp || !acp || !bcp)
    {        
        std::cout << "Error: Point is on the edge of the triangle" << std::endl;
        return false;
    }
    if (abc != abp + acp + bcp)
    {
        std::cout << "Error: Point is outside the triangle" << std::endl;
        return false;
    }
    return abc == abp + acp + bcp;
}