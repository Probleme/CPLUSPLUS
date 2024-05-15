/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:50:35 by ataouaf           #+#    #+#             */
/*   Updated: 2024/05/15 14:07:18 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T *array, size_t length, F func)
{
    if (static_cast<int>(length) < 0)
        return ;
    for (size_t i = 0; i < length; i++)
        func(array[i]);
}

#endif
