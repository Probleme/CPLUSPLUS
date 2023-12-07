/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:59:20 by ataouaf           #+#    #+#             */
/*   Updated: 2023/12/06 10:20:27 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"

Cure::Cure() : AMateria("cure"){
    // std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure& c) : AMateria(c){
    // std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& c){
    (void)c;
    // std::cout << "Cure assignation operator called" << std::endl;
    return *this;
}

Cure::~Cure(){
    // std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const{
    return new Cure;
}

void Cure::use(ICharacter& target){
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
