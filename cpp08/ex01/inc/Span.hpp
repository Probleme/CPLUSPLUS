/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:03:14 by ataouaf           #+#    #+#             */
/*   Updated: 2024/06/27 09:47:50 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
    private:
        unsigned int _n;
        std::vector<int> _v;
    public:
        Span();
        Span(unsigned int n);
        Span(Span const &src);
        ~Span();
        Span &operator=(Span const &src);
        void addNumber(int n);
        int shortestSpan();
        int longestSpan();
        
        template <typename Iterator>
        void addRange(Iterator begin, Iterator end)
        {
            if (std::distance(begin, end) > this->_n)
                throw std::out_of_range("Span is full");
            this->_v.insert(this->_v.end(), begin, end);
        }
};

#endif