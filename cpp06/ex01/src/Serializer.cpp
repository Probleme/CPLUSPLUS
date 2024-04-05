/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Searializer.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:30:27 by ataouaf           #+#    #+#             */
/*   Updated: 2024/04/02 15:22:45 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../inc/Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::~Serializer()
{
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
