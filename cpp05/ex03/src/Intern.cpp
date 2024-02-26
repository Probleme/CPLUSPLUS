/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:40:15 by ataouaf           #+#    #+#             */
/*   Updated: 2024/02/26 20:43:56 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &other)
{
    *this = other;
}

Intern &Intern::operator=(Intern const &other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(std::string const &name, std::string const &target)
{
    if (name == "shrubbery creation")
    {
        std::cout << "Intern creates " << name << std::endl;
        return new ShrubberyCreationForm(target);
    }
    else if (name == "robotomy request")
    {
        std::cout << "Intern creates " << name << std::endl;
        return new RobotomyRequestForm(target);
    }
    else if (name == "presidential pardon")
    {
        std::cout << "Intern creates " << name << std::endl;
        return new PresidentialPardonForm(target);
    }
    else
        throw Intern::FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw()
{
    return "Form not found";
}
