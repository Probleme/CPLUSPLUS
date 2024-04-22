/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 22:45:14 by ataouaf           #+#    #+#             */
/*   Updated: 2024/04/22 13:55:30 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name), _grade(other._grade){}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
    if (this != &other)
    {
        _grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string const &Bureaucrat::getName() const {return _name;}

int Bureaucrat::getGrade() const {return _grade;}

void Bureaucrat::incrementGrade()
{
    if (_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    if (_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {return "Grade is too high";}

const char *Bureaucrat::GradeTooLowException::what() const throw() {return "Grade is too low";}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << _name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form)
{
    try
    {
        form.execute(*this);
        std::cout << _name << " executes " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << _name << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
    }
}
