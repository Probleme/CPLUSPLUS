/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 03:55:13 by ataouaf           #+#    #+#             */
/*   Updated: 2023/11/19 05:46:14 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/Fixed.hpp"
#include "../inc/Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
    Point a(-4, 6);
    Point b(6, 4);
    Point c(-2, 2);
    Point point(1, 2);
    std::cout << bsp(a, b, c, point) << std::endl;
    Point a1(-3, 4);
    Point b1(3, 2);
    Point c1(4, 4);
    Point point1(2, 3);
    std::cout << bsp(a1, b1, c1, point1) << std::endl;
    return 0;
}