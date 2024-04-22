/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:40:15 by ataouaf           #+#    #+#             */
/*   Updated: 2024/04/22 13:38:11 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const &other) {*this = other;}

Intern &Intern::operator=(Intern const &)
{
    return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(std::string const &name, std::string const &target)
{
    AForm *form = NULL;
    std::string forms[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
    for (int i = 0; i < 3; i++)
    {
        if (forms[i] == name)
        {
            switch (i)
            {
                case 0:
                    form = new RobotomyRequestForm(target);
                    break;
                case 1:
                    form = new PresidentialPardonForm(target);
                    break;
                case 2:
                    form = new ShrubberyCreationForm(target);
                    break;
            }
            if (form != NULL)
            {
                std::cout << "Intern creates " << form->getName() << std::endl;
                return (form);
            }
        }
    }
    throw FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw() {return "Form not found";}
