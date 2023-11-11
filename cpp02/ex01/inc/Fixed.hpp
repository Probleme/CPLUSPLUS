/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:11:56 by ataouaf           #+#    #+#             */
/*   Updated: 2023/11/11 00:46:36 by ataouaf          ###   ########.fr       */
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
        float toFloat( void ) const;
        int toInt( void ) const;
};

#endif
