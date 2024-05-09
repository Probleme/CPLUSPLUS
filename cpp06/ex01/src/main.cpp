/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:22:59 by ataouaf           #+#    #+#             */
/*   Updated: 2024/05/08 13:45:52 by ataouaf          ###   ########.fr       */
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
        std::cout << "ptr\t" << ptr << std::endl;
        std::cout << "data\t" << &data << std::endl;
        std::cout << "Num: " << ptr->num << std::endl;
        std::cout << "Str: " << ptr->str << std::endl;
    }
    else
        std::cout << "Different address" << std::endl;
    return 0;
}