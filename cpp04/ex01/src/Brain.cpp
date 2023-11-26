/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 05:05:27 by ataouaf           #+#    #+#             */
/*   Updated: 2023/11/25 05:06:19 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

Brain::Brain(){
    std::cout << "Brain default constructor called!" << std::endl;
}

Brain::Brain(const Brain &b){
    std::cout << "Brain copy constructor called!" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = b.ideas[i];
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
