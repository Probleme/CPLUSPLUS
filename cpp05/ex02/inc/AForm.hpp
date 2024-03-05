/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:37:27 by ataouaf           #+#    #+#             */
/*   Updated: 2024/03/01 15:22:27 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    protected:
        virtual void executeAction() const = 0;
    private:
        std::string const _name;
        bool _signed;
        int const _gradeToSign;
        int const _gradeToExecute;
    public:
        AForm();
        AForm(std::string const &name, int gradeToSign, int gradeToExecute);
        AForm(AForm const &other);
        AForm &operator=(AForm const &other);
        ~AForm();
        std::string const &getName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(Bureaucrat const &bureaucrat);
        void execute(Bureaucrat const &bureaucrat) const;
        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
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

std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif