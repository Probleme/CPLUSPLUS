/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:18:16 by ataouaf           #+#    #+#             */
/*   Updated: 2024/06/28 10:05:03 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <list>

template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C>
{
    public:
        MutantStack() : std::stack<T, C>() {}
        MutantStack(const MutantStack &other) : std::stack<T,C>(other) {}
        MutantStack &operator=(const MutantStack &other)
        {
            this->c = other.c;
            return *this;
        }
        virtual ~MutantStack() {}

        typedef typename C::iterator iterator;

        iterator begin()
        {
            return this->c.begin();
        }

        iterator end()
        {
            return this->c.end();
        }
};

#endif