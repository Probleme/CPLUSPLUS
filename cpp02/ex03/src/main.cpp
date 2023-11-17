/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 03:55:13 by ataouaf           #+#    #+#             */
/*   Updated: 2023/11/17 03:48:02 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/Fixed.hpp"
#include "../inc/Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
    Point a(0, 0);
    Point b(20, 0);
    Point c(10, 30);
    Point point(0, 15);
    std::cout << bsp(a, b, c, point) << std::endl;
    return 0;
}