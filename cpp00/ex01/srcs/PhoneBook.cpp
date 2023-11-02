/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 00:01:23 by ataouaf           #+#    #+#             */
/*   Updated: 2023/10/20 23:17:20 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
    this->_index = 0;
    this->_nbContacts = 0;}

PhoneBook::~PhoneBook(void) {}

bool PhoneBook::addContact(void) {
    std::string infos[5];
    std::string types[5];
    types[0] = "First name: ";
    types[1] = "Last name: ";
    types[2] = "Nickname: ";
    types[3] = "Phone number: ";
    types[4] = "Darkest secret: ";
    for (int i = 0; i < 5; i++){
        std::cout << types[i];
        if (!std::getline(std::cin, infos[i]))
            return false;
        while (!infos[i].length()){
            std::cerr << "This field can't be empty, try again: ";
            if (!std::getline(std::cin, infos[i]))
                return false;
        }
    }
    int index;
    if (this->_index == 7)
        index = 0;
    else
        index = this->_index;
    this->_contacts[index].set_infos(infos[0], infos[1], infos[2], infos[3], infos[4]);
    this->_index = index;
    if (this->_nbContacts < 8)
        this->_nbContacts++;
    return true;
}

void PhoneBook::searchContact(void) const {
    if (!this->_nbContacts){
        std::cout << "There is no Contact Please try to ADD at once 1. Returning to main menu...\n";
        return;
    }
    std::cout << '|' << std::left << std::setw(10) << "Index" << '|'
        << std::setw(10) << "First name" << '|'
        << std::setw(10) << "Last name" << '|'
        << std::setw(10) << "Nickname" << '|' << std::endl;
    for (int i = 0; i < this->_nbContacts; i++)
        this->_contacts[i].print_table(i + 1);
    std::string index;
    std::cout << "\nContact index: ";
    std::getline(std::cin, index);
    if (index.length() != 1 || !std::isdigit(index[0]) || std::atoi(index.c_str()) < 1
        || std::atoi(index.c_str()) > this->_nbContacts){
        std::cout << "Invalid index. Returning to main menu...\n";
        return;
    }
    this->_contacts[std::atoi(index.c_str()) - 1].print_infos();
}
