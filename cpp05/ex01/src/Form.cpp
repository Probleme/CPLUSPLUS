/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:37:17 by ataouaf           #+#    #+#             */
/*   Updated: 2024/04/22 15:52:32 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150){}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(Form const &other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){}

Form &Form::operator=(Form const &other)
{
    if (this != &other)
        *this = other;
    return *this;
}

Form::~Form(){}

std::string const &Form::getName() const{return _name;}

bool Form::getSigned() const {return _signed;}

int Form::getGradeToSign() const {return _gradeToSign;}

int Form::getGradeToExecute() const {return _gradeToExecute;}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw Form::GradeTooLowException();
    if (_signed)
        throw Form::FormAlreadySignedException();
    _signed = true;
}

const char *Form::GradeTooHighException::what() const throw() {return "Grade is too high";}

const char *Form::GradeTooLowException::what() const throw() {return "Grade is too low";}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
    out << "Form " << form.getName() << " is ";
    if (form.getSigned())
    {
        out << "signed";
        return out;
    }
    else
        out << "not signed and requires a grade " << form.getGradeToSign() << " to sign and a grade " << form.getGradeToExecute() << " to execute";
    return out;
}
