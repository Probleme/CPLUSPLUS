/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:40:23 by ataouaf           #+#    #+#             */
/*   Updated: 2024/03/05 16:53:53 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(Intern const &other);
        Intern &operator=(Intern const &other);
        ~Intern();
        AForm *makeForm(std::string const &name, std::string const &target);
        class FormNotFoundException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

#endif