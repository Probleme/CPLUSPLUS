/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 02:45:37 by ataouaf           #+#    #+#             */
/*   Updated: 2023/11/26 03:21:03 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
    std::cout << "WrongCat default constructor called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &wc) : WrongAnimal(wc){
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = wc;
}

WrongCat& WrongCat::operator=(const WrongCat &wc){
    std::cout << "WrongCat assignation operator called" << std::endl;
    this->type = wc.type;
    return *this;
}

WrongCat::~WrongCat(){
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const{
    std::cout << "WrongCat sound" << std::endl;
}
