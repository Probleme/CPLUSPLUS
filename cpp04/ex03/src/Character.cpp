/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:35:38 by ataouaf           #+#    #+#             */
/*   Updated: 2023/12/06 10:56:42 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"

Character::Character()  : _name("default"), _materias(new AMateria*[4]),  _count(0){
    // std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
}

Character::Character(std::string const& name) : _name(name), _materias(new AMateria*[4]),  _count(0){
    // std::cout << "Character parametric constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
}

Character::Character(const Character& c) : _name(c._name), _materias(new AMateria*[4]),  _count(0){
    // std::cout << "Character copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++){
        if (c._inventory[i] != NULL)
            this->_inventory[i] = c._inventory[i]->clone();
    }
}

Character& Character::operator=(const Character& c){
    // std::cout << "Character assignation operator called" << std::endl;
    if (this == &c)
        return *this;
    this->_name = c._name;
    this->_count = c._count;
    for (int i = 0; i < 4; i++){
        unequip(i);
        if (c._inventory[i])
            this->_inventory[i] = c._inventory[i]->clone();
        else
            this->_inventory[i] = NULL;
    }
    return *this;
}

Character::~Character(){ 
    // std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < 4; i++){
        if (this->_inventory[i] != NULL)
        {
            delete this->_inventory[i];
            this->_inventory[i] = NULL;
        }
    }
    for (int i = 0; i < _count; i++)
        delete _materias[i];
    delete [] _materias;
    _materias = NULL;
}

std::string const & Character::getName() const{
    return this->_name;
}

void Character::equip(AMateria *m){
    if (!m)
        return;
    int index = 0;
    for (int i = 0; i < 4 && this->_inventory[i]; i++){
        if (this->_inventory[i] == m)
            return;
        index++;
    }
    if (index == 4)
    {
        std::cout << "Inventory is full" << std::endl;
        delete m;
        return;
    }
    this->_inventory[index] = m;
}

void Character::unequip(int idx){
    if (idx < 0 || idx >= 4 || !this->_inventory[idx])
        return;
    for (int idx = 0; idx < 4 && this->_materias[idx]; idx++)
    {
        if (this->_inventory[idx] == this->_materias[idx])
            return;
    }
	this->_materias[this->_count] = this->_inventory[idx];
	this->_count += 1;
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target){
    if (idx < 0 || idx >= 4 || !this->_inventory[idx])
        return;
    this->_inventory[idx]->use(target);
}
