/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 03:50:29 by ataouaf           #+#    #+#             */
/*   Updated: 2023/11/25 01:54:08 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = other;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &other)
{
    std::cout << "ClapTrap copy assignement operator called" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
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
        std::cout << "ClapTrap " << this->_name << " can't be repaired with negative amount!" << std::endl;
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