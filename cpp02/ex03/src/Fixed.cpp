/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 03:55:07 by ataouaf           #+#    #+#             */
/*   Updated: 2023/11/17 03:48:08 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0){}

Fixed::Fixed(const Fixed& other) : _fixedPointValue(other._fixedPointValue){}

Fixed& Fixed::operator=(const Fixed& other){
    if (this == & other)
        return *this;
    this->_fixedPointValue = other._fixedPointValue;
    return *this;
}

Fixed::Fixed(const int intValue) : _fixedPointValue(intValue << _fractionalBits){}

Fixed::Fixed(const float floatValue) : _fixedPointValue(roundf(floatValue * (1 << _fractionalBits))){}

Fixed::~Fixed(){}

int Fixed::getRawBits() const{
    return _fixedPointValue;
}

void Fixed::setRawBits(int const raw){
    this->_fixedPointValue = raw;
}

float Fixed::toFloat( void ) const{
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::toInt( void ) const{
    return _fixedPointValue >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed){
    return os << fixed.toFloat();
}

bool Fixed::operator>(const Fixed& other) const{
    return this->_fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed& other) const{
    return this->_fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed& other) const{
    return this->_fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed& other) const{
    return this->_fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed& other) const{
    return this->_fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed& other) const{
    return this->_fixedPointValue != other._fixedPointValue;
}

Fixed Fixed::operator+(const Fixed& other) const{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const{
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++(){
    this->_fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int){
    Fixed tmp(*this);
    ++(*this);
    return tmp;
}

Fixed& Fixed::operator--(){
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int){
    Fixed tmp(*this);
    --(*this);
    return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b){
    return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b){
    return a > b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
    return a < b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
    return a > b ? a : b;
}
