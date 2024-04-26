/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:22:59 by ataouaf           #+#    #+#             */
/*   Updated: 2024/04/20 15:07:57 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

int main()
{
    Data data;
    data.num = 42;
    data.str = "Hello World";

    Data data2;
    data2.num = 21;
    data2.str = "World Hello";
    
    uintptr_t raw2 = Serializer::serialize(&data2);
    Data* ptr2 = Serializer::deserialize(raw2);
    
    if (ptr2 == &data2)
    {
        std::cout << "Same address" << std::endl;
        std::cout << "ptr2\t" << ptr2 << std::endl;
        std::cout << "data2\t" << &data2 << std::endl;
        std::cout << "Num: " << ptr2->num << std::endl;
        std::cout << "Str: " << ptr2->str << std::endl;
    }
    else
        std::cout << "Different address" << std::endl;

        
    uintptr_t raw = Serializer::serialize(&data);
    Data* ptr = Serializer::deserialize(raw);
    
    

    if (ptr == &data)
    {
        std::cout << "Same address" << std::endl;
        std::cout << "ptr\t" << ptr << std::endl;
        std::cout << "data\t" << &data << std::endl;
        std::cout << "Num: " << ptr->num << std::endl;
        std::cout << "Str: " << ptr->str << std::endl;
    }
    else
        std::cout << "Different address" << std::endl;
    return 0;
}