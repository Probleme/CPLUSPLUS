/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:42:18 by ataouaf           #+#    #+#             */
/*   Updated: 2023/11/26 03:07:14 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"
#include "../inc/Brain.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << std::endl;
    std::cout << "Animal:" << std::endl;
    std::cout << "Type: " << meta->getType() << std::endl;
    meta->makeSound();
    std::cout << std::endl;
    std::cout << "Dog:" << std::endl;
    std::cout << "Type: " << j->getType() << std::endl;
    j->makeSound();
    std::cout << std::endl;
    std::cout << "Cat:" << std::endl;
    std::cout << "Type: " << i->getType() << std::endl;
    i->makeSound();
    std::cout << std::endl;

    const WrongAnimal* wrongMeta = new WrongAnimal();
    // const WrongAnimal* wrongJ = new WrongCat();

    std::cout << std::endl;
    std::cout << "WrongAnimal:" << std::endl;
    std::cout << "Type: " << wrongMeta->getType() << std::endl;
    wrongMeta->makeSound();
    std::cout << std::endl;
    // std::cout << "WrongCat:" << std::endl;
    // std::cout << "Type: " << wrongJ->getType() << std::endl;
    // wrongJ->makeSound();
    // std::cout << std::endl;

    const Brain* brain = new Brain();
    std::cout << std::endl;
    std::cout << "Brain:" << std::endl;
    std::cout << "Idea 1: " << brain->getIdea(0) << std::endl;
    std::cout << "Idea 2: " << brain->getIdea(1) << std::endl;
    std::cout << "Idea 3: " << brain->getIdea(2) << std::endl;
    std::cout << "Idea 4: " << brain->getIdea(3) << std::endl;
    std::cout << "Idea 5: " << brain->getIdea(4) << std::endl;
    return 0;
}