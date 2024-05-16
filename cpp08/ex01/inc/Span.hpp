/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:03:14 by ataouaf           #+#    #+#             */
/*   Updated: 2024/04/27 12:11:17 by ataouaf          ###   ########.fr       */
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
        class FullContainerException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class NoSpanException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        template <typename Iterator>
        void addRange(Iterator begin, Iterator end)
        {
            if (this->_v.size() + std::distance(begin, end) > this->_n)
                throw Span::FullContainerException();
            this->_v.insert(this->_v.end(), begin, end);
        }
};

#endif