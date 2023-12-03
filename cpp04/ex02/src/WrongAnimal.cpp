/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 02:46:07 by ataouaf           #+#    #+#             */
/*   Updated: 2023/11/26 04:11:18 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
    std::cout << "WrongAnimal default constructor called" << std::endl;
    this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &wa){
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = wa;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &wa){
    std::cout << "WrongAnimal assignation operator called" << std::endl;
    this->type = wa.type;
    return *this;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const{
    return this->type;
}

void WrongAnimal::makeSound() const{
    std::cout << "WrongAnimal sound" << std::endl;
}
