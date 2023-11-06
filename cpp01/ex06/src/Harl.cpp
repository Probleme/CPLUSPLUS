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

Harl::Harl() { }

Harl::~Harl() { }

void Harl::debug() const
{
    std::cout << "[ DEBUG ] " << std::endl << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void Harl::info() const
{
    std::cout << "[ INFO ]" << std::endl << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() const
{
    std::cout << "[ WARNING ]" << std::endl << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()  const
{
    std::cout << "[ ERROR ]" << std::endl << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    void (Harl::*ptr[4])() const = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    if (level == levels[0] || level == levels[1] || level == levels[2] || level == levels[3])
    {
        switch (level[0])
        {
            case 'D':
                (this->*ptr[0])();
            case 'I':
                (this->*ptr[1])();
            case 'W':
                (this->*ptr[2])();
            case 'E':
                (this->*ptr[3])();
                break;
        }
    }
    else
        std::cout << "[ UNKNOWN ]" << std::endl << "Probably complaining about insignificant problems" << std::endl;
}
