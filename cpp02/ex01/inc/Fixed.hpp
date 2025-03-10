/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:11:56 by ataouaf           #+#    #+#             */
/*   Updated: 2023/11/16 02:06:57 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
    private :
        int _fixedPointValue;
        static const int _fractionalBits = 8;
    public :
        Fixed();
        Fixed(const int intValue);
        Fixed(const float floatValue);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
        int getRawBits() const;
        void setRawBits(int const raw);
        int toInt( void ) const;
        float toFloat( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
