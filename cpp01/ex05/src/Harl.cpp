/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:54:03 by ataouaf           #+#    #+#             */
/*   Updated: 2023/10/22 23:34:41 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

Harl::Harl()
{
    complainMap["DEBUG"] = &Harl::debug;
    complainMap["INFO"] = &Harl::info;
    complainMap["WARNING"] = &Harl::warning;
    complainMap["ERROR"] = &Harl::error;
}

Harl::~Harl()
{
}

void Harl::debug() const
{
    std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void Harl::info() const
{
    std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() const
{
    std::cout << "WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()  const
{
    std::cout << "ERROR: This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) const
{
    if (complainMap.find(level) != complainMap.end())
        (this->*complainMap.at(level))();
    else
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}