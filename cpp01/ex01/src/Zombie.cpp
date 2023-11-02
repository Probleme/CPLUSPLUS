/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:39:07 by ataouaf           #+#    #+#             */
/*   Updated: 2023/10/22 18:40:46 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

void Zombie::announce()
{
    std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{
    std::cout << "Zombie is born" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->_name << " is dead" << std::endl;
}

void Zombie::setName(std::string const name)
{
    this->_name = name;
}