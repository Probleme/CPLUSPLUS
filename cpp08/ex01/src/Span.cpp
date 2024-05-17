/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:04:07 by ataouaf           #+#    #+#             */
/*   Updated: 2024/05/17 13:48:17 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

Span::Span() : _n(0) {}

Span::Span(unsigned int n) : _n(n) {}

Span::Span(Span const &src)
{
    *this = src;
}

Span::~Span() {}

Span &Span::operator=(Span const &src)
{
    if (this != &src)
    {
        this->_n = src._n;
        this->_v = src._v;
    }
    return *this;
}

void Span::addNumber(int n)
{
    if (this->_v.size() >= this->_n)
        throw std::out_of_range("Span is full");
    this->_v.push_back(n);
}

int Span::shortestSpan()
{
    if (this->_v.size() <= 1)
        throw std::logic_error("No span to find");
    std::sort(this->_v.begin(), this->_v.end());
    // int min = this->_v[1] - this->_v[0];
    int min = std::numeric_limits<int>::max();
    for (size_t i = 1; i < this->_v.size(); i++)
    {
        int diff = this->_v[i] - this->_v[i - 1];
        if (diff < min)
            min = diff;
        // if (this->_v[i] - this->_v[i - 1] < min)
        //     min = this->_v[i] - this->_v[i - 1];
    }
    return min;
}

int Span::longestSpan()
{
    if (this->_v.size() <= 1)
        throw std::logic_error("No span to find");
    std::sort(this->_v.begin(), this->_v.end());
    return this->_v[this->_v.size() - 1] - this->_v[0];
}

// int shortestSpan() const {
//         if (numbers.size() < 2) {
//             throw std::logic_error("Not enough numbers to find a span");
//         }
//         std::vector<int> sorted_numbers = numbers;
//         std::sort(sorted_numbers.begin(), sorted_numbers.end());

//         int min_span = std::numeric_limits<int>::max();
//         for (size_t i = 1; i < sorted_numbers.size(); ++i) {
//             int span = sorted_numbers[i] - sorted_numbers[i - 1];
//             if (span < min_span) {
//                 min_span = span;
//             }
//         }
//         return min_span;
//     }

//     int longestSpan() const {
//         if (numbers.size() < 2) {
//             throw std::logic_error("Not enough numbers to find a span");
//         }
//         int min_number = *std::min_element(numbers.begin(), numbers.end());
//         int max_number = *std::max_element(numbers.begin(), numbers.end());
//         return max_number - min_number;
//     }
