/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 04:22:12 by ataouaf           #+#    #+#             */
/*   Updated: 2023/11/24 23:54:43 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &scavTrap) : ClapTrap(scavTrap)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = scavTrap;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &scavTrap)
{
    std::cout << "ScavTrap copy assignement operator called" << std::endl;
    if (this != &scavTrap)
    {
        this->_name = scavTrap._name;
        this->_hitPoints = scavTrap._hitPoints;
        this->_energyPoints = scavTrap._energyPoints;
        this->_attackDamage = scavTrap._attackDamage;
    }
    return (*this);
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->_name << " has enterred in Gate keeper mode" << std::endl;
}