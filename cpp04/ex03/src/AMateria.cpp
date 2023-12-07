/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:54:24 by ataouaf           #+#    #+#             */
/*   Updated: 2023/12/06 10:17:13 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"

AMateria::AMateria() : _type("default"){
    // std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const& type) : _type(type){
    // std::cout << "AMateria parametric constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &a){
    // std::cout << "AMateria copy constructor called" << std::endl;
    *this = a;
}

AMateria& AMateria::operator=(const AMateria &a){
    // std::cout << "AMateria assignation operator called" << std::endl;
    if (this == &a)
        return *this;
    this->_type = a._type;
    return *this;
}

AMateria::~AMateria(){
    // std::cout << "AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType() const{
    return this->_type;
}

void AMateria::use(ICharacter& target){
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
