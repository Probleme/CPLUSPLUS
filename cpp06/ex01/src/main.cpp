/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:22:59 by ataouaf           #+#    #+#             */
/*   Updated: 2024/04/02 15:31:00 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

int main()
{
    Data data;
    data.num = 42;
    data.str = "Hello World";

    uintptr_t raw = Serializer::serialize(&data);
    Data* ptr = Serializer::deserialize(raw);

    if (ptr == &data)
    {
        std::cout << "Same address" << std::endl;
        std::cout << "Num: " << ptr->num << std::endl;
        std::cout << "Str: " << ptr->str << std::endl;
        
    }
    else
        std::cout << "Different address" << std::endl;
    return 0;
}