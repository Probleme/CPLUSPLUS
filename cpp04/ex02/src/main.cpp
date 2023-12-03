/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:42:18 by ataouaf           #+#    #+#             */
/*   Updated: 2023/12/03 16:06:07 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AAnimal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Brain.hpp"

int main()
{
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    std::cout << std::endl;
    delete i;
    delete j;
    std::cout << std::endl;
    Dog basic;
    {
        Dog tmp = basic;
    }
    return 0;
}