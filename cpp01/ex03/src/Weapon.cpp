/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:06:37 by ataouaf           #+#    #+#             */
/*   Updated: 2023/10/22 20:02:34 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
    std::cout << "Weapon " << type << " created" << std::endl;
}

Weapon::~Weapon()
{
    std::cout << "Weapon " << this->_type << " destroyed" << std::endl;
}

std::string const &Weapon::getType(void) const
{
    return (this->_type);
}

void Weapon::setType(std::string const& type)
{
    std::cout << this->_type << " changed to " << type << std::endl;
    this->_type = type;
}