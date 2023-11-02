/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 05:05:50 by ataouaf           #+#    #+#             */
/*   Updated: 2023/10/20 05:35:17 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"
#include <iostream>
#include <iomanip>
#include <ostream>

Contact::Contact() {}

Contact::~Contact() {}

void Contact::print_table(int index) const {
    std::cout << '|' << std::right << std::setw(10) << index << '|';
    if (this->_firstName.length() > 10)
        std::cout << this->_firstName.substr(0, 9) << ".|";
    else
        std::cout << std::setw(10) << this->_firstName << '|';
    if (this->_lastName.length() > 10)
        std::cout << this->_lastName.substr(0, 9) << ".|";
    else
        std::cout << std::setw(10) << this->_lastName << '|';
    if (this->_nickname.length() > 10)
        std::cout << this->_nickname.substr(0, 9) << '.';
    else
        std::cout << std::setw(10) << this->_nickname;
    std::cout << '|' << std::endl;
}

void Contact::print_infos(void) const {
    std::cout << "\e[1mFirst name:\e[0m " << this->_firstName << std::endl
        << "\e[1mLast name:\e[0m " << this->_lastName << std::endl
        << "\e[1mNickname:\e[0m " << this->_nickname << std::endl
        << "\e[1mPhone Number:\e[0m " << this->_phoneNumber << std::endl
        << "\e[1mDarkest Secret:\e[0m " << this->_darkestSecret << std::endl;
}

void Contact::set_infos(std::string firstName, std::string lastName,
 std::string nickname, std::string phoneNumber, std::string darkestSecret) {

    this->_firstName = firstName;
    this->_lastName = lastName;
    this->_nickname = nickname;
    this->_phoneNumber = phoneNumber;
    this->_darkestSecret = darkestSecret;
    return ;
}
