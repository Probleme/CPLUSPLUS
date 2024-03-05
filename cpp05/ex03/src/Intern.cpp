/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:40:15 by ataouaf           #+#    #+#             */
/*   Updated: 2024/03/05 17:10:02 by ataouaf          ###   ########.fr       */
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
    AForm *form = nullptr;
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
            if (form != nullptr)
            {
                std::cout << "Intern creates " << form->getName() << std::endl;
                return (form);
            }
        }
    }
    throw FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw()
{
    return "Form not found";
}
