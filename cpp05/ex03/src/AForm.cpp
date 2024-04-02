/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:37:17 by ataouaf           #+#    #+#             */
/*   Updated: 2024/04/01 16:29:08 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

AForm &AForm::operator=(AForm const &other)
{
    if (this != &other)
    {
        _signed = other._signed;
    }
    return *this;
}

AForm::~AForm() {}

std::string const &AForm::getName() const {return _name;}

bool AForm::getSigned() const {return _signed;}

int AForm::getGradeToSign() const {return _gradeToSign;}

int AForm::getGradeToExecute() const {return _gradeToExecute;}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw AForm::GradeTooLowException();
    _signed = true;
}

const char *AForm::FormNotSignedException::what() const throw() {return "Form is not signed";}

const char *AForm::GradeTooHighException::what() const throw() {return "Grade is too high";}

const char *AForm::GradeTooLowException::what() const throw() {return "Grade is too low";}

std::ostream &operator<<(std::ostream &out, AForm const &form)
{
    out << "Form " << form.getName() << " is ";
    if (form.getSigned())
        out << "signed";
    else
        out << "not signed";
    out << " and requires a grade " << form.getGradeToSign() << " to sign and a grade " << form.getGradeToExecute() << " to execute";
    return out;
}
