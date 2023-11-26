/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:42:18 by ataouaf           #+#    #+#             */
/*   Updated: 2023/11/26 04:04:41 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"

int main(){
    WrongAnimal* wrong = new WrongCat();
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << std::endl;
    std::cout << "meta->getType(): " << meta->getType() << std::endl;
    std::cout << "j->getType(): " << j->getType() << std::endl;
    std::cout << "i->getType(): " << i->getType() << std::endl;
    std::cout << "wrong->getType(): " << wrong->getType() << std::endl;

    std::cout << "meta->makeSound(): ";
    meta->makeSound();
    std::cout << "j->makeSound(): ";
    j->makeSound();
    std::cout << "i->makeSound(): ";
    i->makeSound();
    std::cout << "wrong->makeSound(): ";
    wrong->makeSound();
    std::cout << std::endl;

    delete i;
    delete j;
    delete meta;
    delete wrong;
    return 0;
}