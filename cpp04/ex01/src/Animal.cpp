/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:31:23 by ataouaf           #+#    #+#             */
/*   Updated: 2023/12/04 11:03:38 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Animal::Animal() : type("Animal"){
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &a) : type(a.type){
    std::cout << "Animal copy constructor called" << std::endl;
    *this = a;
}

Animal& Animal::operator=(const Animal &a){
    std::cout << "Animal assignation operator called" << std::endl;
    if (this != &a)
        this->type = a.type;
    return *this;
}

Animal::~Animal(){
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const{
    return this->type;
}
