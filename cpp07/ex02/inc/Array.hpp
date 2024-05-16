/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:39:10 by ataouaf           #+#    #+#             */
/*   Updated: 2024/05/16 17:10:52 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
    private:
        T *_array;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(Array const &other);
        ~Array();
        Array &operator=(Array const &other);
        T &operator[](unsigned int index) const;
        unsigned int size() const;
};

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n)
{
    _array = new T[n]();
    _size = n;
}

template <typename T>
Array<T>::Array(Array const &other) : _array(new T[other._size]()), _size(other._size)
{
    for (unsigned int i = 0; i < _size; i++)
        _array[i] = other._array[i];
}

template <typename T>
Array<T>::~Array()
{
    delete[] _array;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other)
{
    if (this != &other)
    {
        delete[] _array;
        _array = new T[other._size]();
        _size = other._size;
        for (unsigned int i = 0; i < _size; i++)
            _array[i] = other._array[i];
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw std::out_of_range("Index out of range");
    return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}

#endif