/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 05:05:27 by ataouaf           #+#    #+#             */
/*   Updated: 2023/12/03 15:42:05 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

Brain::Brain(){
    std::cout << "Brain default constructor called!" << std::endl;
}

Brain::Brain(const Brain &b){
    std::cout << "Brain copy constructor called!" << std::endl;
    *this = b;
}

Brain& Brain::operator=(const Brain &b){
    std::cout << "Brain assignement operator called!" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = b.ideas[i];
    return *this;
}

Brain::~Brain(){
    std::cout << "Brain destructor called!" << std::endl;
}

std::string Brain::getIdea(int i) const{
    return this->ideas[i];
}

void Brain::setIdea(int i, std::string idea){
    this->ideas[i] = idea;
}
