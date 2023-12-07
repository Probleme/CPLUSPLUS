/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:42:13 by ataouaf           #+#    #+#             */
/*   Updated: 2023/12/06 10:26:42 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MateriaSource.hpp"

MateriaSource::MateriaSource(){
    // std::cout << "MateriaSource default constructor called" << std::endl;
    this->_count = 0;
    for (int i = 0; i < 4; i++)
        this->_materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &m){
    // std::cout << "MateriaSource copy constructor called" << std::endl;
    *this = m;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &m){
    // std::cout << "MateriaSource assignation operator called" << std::endl;
    if (this == &m)
        return *this;
    this->_count = m._count;
    for (int i = 0; i < 4; i++)
    {
        if (this->_materias[i] != NULL)
        {
            delete(this->_materias[i]);
            this->_materias[i] = NULL;
        }
        if (m._materias[i] != NULL)
            this->_materias[i] = m._materias[i]->clone();
        else
            this->_materias[i] = NULL;
    }
    return *this;
}

MateriaSource::~MateriaSource(){
    // std::cout << "MateriaSource destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->_materias[i] != NULL)
        {
            delete(this->_materias[i]);
            this->_materias[i] = NULL;
        }
    }
}

void MateriaSource::learnMateria(AMateria *m){
    if (this->_count == 4)
    {
        std::cout << "MateriaSource is full" << std::endl;
        delete m;
        return ;
    }
    if (this->_count < 4 && m != NULL)
    {
        this->_materias[this->_count] = m;
        this->_count++;
    }
}

AMateria* MateriaSource::createMateria(std::string const & type){
    for (int i = 0; i < this->_count; i++){
        if (this->_materias[i]->getType() == type)
            return this->_materias[i]->clone();
    }
    return NULL;
}
