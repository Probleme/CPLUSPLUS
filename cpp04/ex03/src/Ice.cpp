/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:55:05 by ataouaf           #+#    #+#             */
/*   Updated: 2023/12/06 10:19:06 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ice.hpp"

Ice::Ice() : AMateria("ice"){
    // std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice& i) : AMateria(i){
    // std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& i){
    (void)i;
    // std::cout << "Ice assignation operator called" << std::endl;
    return *this;
}

Ice::~Ice(){
    // std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const{
    return new Ice;
}

void Ice::use(ICharacter& target){
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
