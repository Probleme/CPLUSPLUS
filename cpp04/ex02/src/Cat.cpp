/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:40:46 by ataouaf           #+#    #+#             */
/*   Updated: 2023/12/03 15:49:22 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat(){
    std::cout << "Cat default constructor called" << std::endl;
    this->type = "Cat";
    this->_brain = new Brain();
}

Cat::Cat(const Cat &c){
    std::cout << "Cat copy constructor called" << std::endl;
    *this = c;
}

Cat& Cat::operator=(const Cat &c){
    std::cout << "Cat assignation operator called" << std::endl;
    this->type = c.type;
    this->_brain = new Brain(*c._brain);
    return *this;
}

Cat::~Cat(){
    delete this->_brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const{
    std::cout << "Cat sound" << std::endl;
}
