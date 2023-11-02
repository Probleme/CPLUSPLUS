/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:09:40 by ataouaf           #+#    #+#             */
/*   Updated: 2023/10/22 20:07:10 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanA.hpp"

HumanA::HumanA(std::string const& name, Weapon const& weapon) : _name(name), _weapon(weapon)
{
    std::cout << "HumanA is born" << std::endl;
}

HumanA::~HumanA()
{
    std::cout << "HumanA is died" << std::endl;
}

void HumanA::attack(void) const
{
    std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}
