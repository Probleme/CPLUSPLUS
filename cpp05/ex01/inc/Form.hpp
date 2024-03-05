/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:37:27 by ataouaf           #+#    #+#             */
/*   Updated: 2024/03/01 12:56:23 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        std::string const _name;
        bool _signed;
        int const _gradeToSign;
        int const _gradeToExecute;
    public:
        Form();
        Form(std::string const &name, int gradeToSign, int gradeToExecute);
        Form(Form const &other);
        Form &operator=(Form const &other);
        ~Form();
        std::string const &getName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(Bureaucrat const &bureaucrat);
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif