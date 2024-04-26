/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:50:35 by ataouaf           #+#    #+#             */
/*   Updated: 2024/04/25 18:44:12 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, int size, void (*func)(T const &))
{
    if (!array || size < 0 || !func)
        return;
    for (int i = 0; i < size; i++)
        func(array[i]);
}

#endif