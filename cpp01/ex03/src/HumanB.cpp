/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:11:12 by ataouaf           #+#    #+#             */
/*   Updated: 2023/10/22 19:59:01 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"

HumanB::HumanB(std::string const name) : _name(name)
{
	std::cout << "HumanB is Born" << std::endl;
}

HumanB::~HumanB()
{
    std::cout << "HumanB is died" << std::endl;
}

void HumanB::attack(void) const
{
    if (this->_weapon)
        std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
    else
        std::cout << this->_name << " has no weapon" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
    std::cout << this->_name << " found a new weapon: " << this->_weapon->getType() << std::endl;
}
