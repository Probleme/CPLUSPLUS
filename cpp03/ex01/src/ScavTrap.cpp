/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 04:22:12 by ataouaf           #+#    #+#             */
/*   Updated: 2023/12/05 11:34:16 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap Default constructor called" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap constructor called" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
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

void ScavTrap::attack(std::string const &target)
{
    if (target.empty())
    {
        std::cout << "ScavTrap " << this->_name << " can't attack empty target!" << std::endl;
        return ;
    }
    if (this->_name.empty())
    {
        std::cout << "ScavTrap can't attack " << target << " without name!" << std::endl;
        return ;
    }
    if (this->_energyPoints > 0 && this->_hitPoints > 0)
    {
        std::cout << "ScavTrap " << this->_name << " attack " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints--;
    }
    else
        std::cout << "ScavTrap " << this->_name << " has no energy points!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->_name << " has enterred in Gate keeper mode" << std::endl;
}