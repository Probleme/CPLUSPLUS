/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 03:55:13 by ataouaf           #+#    #+#             */
/*   Updated: 2023/11/16 03:55:14 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/Fixed.hpp"

int main()
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl; // 0
    std::cout << ++a << std::endl; // 1
    std::cout << a << std::endl; // 1
    std::cout << a++ << std::endl; // 1
    std::cout << a << std::endl; // 2
    std::cout << b << std::endl; // 10.1015625
    std::cout << Fixed( 5.05f ) + Fixed( 2 ) << std::endl; // 7.05078
    std::cout << Fixed( 5.05f ) - Fixed( 2 ) << std::endl; // 3.05078
    std::cout << Fixed( 5.05f ) / Fixed( 2 ) << std::endl; // 2.52734
    std::cout << Fixed( 5.05f ) * Fixed( 2 ) << std::endl; // 10.1016
    Fixed c( 10 );
    Fixed d( 10.42f );
    std::cout << (c > d) << std::endl; // 0
    std::cout << (c < d) << std::endl; // 1
    std::cout << (c >= d) << std::endl; // 0
    std::cout << (c <= d) << std::endl; // 1
    std::cout << (c == d) << std::endl; // 0
    std::cout << (c != d) << std::endl; // 1
    a = Fixed( 10.42f );
    std::cout << a << std::endl; // 10.4219
    std::cout << a-- << std::endl; // 10.4219
    std::cout << a << std::endl; // 10.418
    std::cout << --a << std::endl; // 10.4141
    std::cout << a << std::endl; // 10.4141
    std::cout << Fixed::max( a, b ) << std::endl; // 10.4141
    std::cout << Fixed::min( a, b ) << std::endl; // 10.1016
    return 0;
}