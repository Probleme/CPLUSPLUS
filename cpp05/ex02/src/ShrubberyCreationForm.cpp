/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:32:08 by ataouaf           #+#    #+#             */
/*   Updated: 2024/04/22 14:03:01 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default"){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other), _target(other._target){}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
    if (this != &other)
    {
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    if (!this->getSigned())
        throw AForm::FormNotSignedException();
    std::ofstream file;
    file.open(_target + "_shrubbery");
    if (!file.is_open())
        throw AForm::FileNotOpenedException();
    file << "      /\\      " << std::endl;
    file << "     /\\*\\     " << std::endl;
    file << "    /\\O\\*\\    " << std::endl;
    file << "   /*/\\/\\/\\   " << std::endl;
    file << "  /\\O\\/\\*\\/\\  " << std::endl;
    file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
    file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
    file << "      ||      " << std::endl;
    file << "      ||      " << std::endl;
    file << "      ||      " << std::endl;
    file << "   __ || __   " << std::endl;
    file << "  \\######/  " << std::endl;
    file << "   \\####/   " << std::endl;
    file << "    \\##/    " << std::endl;
    file << "     \\#/     " << std::endl;
    file.close();
}
