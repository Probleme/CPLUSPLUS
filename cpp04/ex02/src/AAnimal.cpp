/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:31:23 by ataouaf           #+#    #+#             */
/*   Updated: 2023/12/03 16:06:59 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AAnimal.hpp"

AAnimal::AAnimal() : type("Animal"){
    std::cout << "Animal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &a) : type(a.type){
    std::cout << "Animal copy constructor called" << std::endl;
    *this = a;
}

AAnimal& AAnimal::operator=(const AAnimal &a){
    std::cout << "Animal assignation operator called" << std::endl;
    this->type = a.type;
    return *this;
}

AAnimal::~AAnimal(){
    std::cout << "Animal destructor called" << std::endl;
}

std::string AAnimal::getType() const{
    return this->type;
}

void AAnimal::makeSound() const{
    std::cout << "Animal sound" << std::endl;
}
