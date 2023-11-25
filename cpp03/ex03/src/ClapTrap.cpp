/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 03:50:29 by ataouaf           #+#    #+#             */
/*   Updated: 2023/11/25 02:19:04 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hitPoints(100), _energyPoints(100), _attackDamage(30)
{
    std::cout << "Default constructor called ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(100), _energyPoints(100), _attackDamage(30)
{
    std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &clapTrap)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = clapTrap;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &clapTrap)
{
    std::cout << "ClapTrap copy assignement operator called" << std::endl;
    if (this != &clapTrap)
    {
        this->_name = clapTrap._name;
        this->_hitPoints = clapTrap._hitPoints;
        this->_energyPoints = clapTrap._energyPoints;
        this->_attackDamage = clapTrap._attackDamage;
    }
    return (*this);
}

void ClapTrap::attack(std::string const &target)
{
    if (this->_energyPoints > 0 && this->_hitPoints > 0)
    {
        std::cout << "ClapTrap " << this->_name << " attack " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints--;
    }
    else
        std::cout << "ClapTrap " << this->_name << " has no energy points left to attack!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if ((int)amount < 0)
    {
        std::cout << "ClapTrap " << this->_name << " can't take negative damage!" << std::endl;
        return ;
    }
    if (this->_hitPoints > 0)
    {
        this->_hitPoints -= amount;
        std::cout << "ClapTrap " << this->_name << " take " << amount << " points of damage!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->_name << " has no hit points left!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if ((int)amount < 0)
    {
        std::cout << "ClapTrap " << this->_name << " can't be repaired with negative amount of hit points!" << std::endl;
        return ;
    }
    if (this->_energyPoints > 0 && this->_hitPoints > 0)
    {
        this->_hitPoints += amount;
        std::cout << "ClapTrap " << this->_name << " is repaired for " << amount << " hit points!" << std::endl;
        this->_energyPoints--;
    }
    else
        std::cout << "ClapTrap " << this->_name << " has no energy points left to be repaired!" << std::endl;
}