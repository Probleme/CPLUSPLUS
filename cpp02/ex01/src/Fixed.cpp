/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:22:52 by ataouaf           #+#    #+#             */
/*   Updated: 2023/11/11 00:47:33 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _fixedPointValue(other._fixedPointValue){
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed&other){
    std::cout << "Copy assignement operator called" << std::endl;
    if (this != & other)
        _fixedPointValue = other._fixedPointValue;
    return *this;
}

Fixed::Fixed(const int intValue){
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const float floatValue){
    std::cout << "Int constructor called" << std::endl;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const{
    std::cout << "getRawBits member function called" << std::endl;
    return _fixedPointValue;
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called" << std::endl;
    _fixedPointValue = raw;
}
