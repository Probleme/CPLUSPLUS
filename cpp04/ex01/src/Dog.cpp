/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:36:43 by ataouaf           #+#    #+#             */
/*   Updated: 2023/12/04 10:53:05 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog() : Animal(){
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
    this->_brain = new Brain();
}

Dog::Dog(const Dog &d) : Animal(d){
    std::cout << "Dog copy constructor called" << std::endl;
    this->type = d.type;
    this->_brain = new Brain(*d._brain);
}

Dog& Dog::operator=(const Dog &d){
    std::cout << "Dog assignation operator called" << std::endl;
    delete this->_brain;
    this->type = d.type;
    this->_brain = new Brain(*d._brain);
    return *this;
}

Dog::~Dog(){
    delete this->_brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const{
    std::cout << "Dog sound" << std::endl;
}
