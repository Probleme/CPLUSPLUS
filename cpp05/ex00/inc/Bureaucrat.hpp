/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:47:00 by ataouaf           #+#    #+#             */
/*   Updated: 2024/04/22 12:56:18 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREUCRAT_HPP
#define BUREUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
    private:
        std::string const _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string const &name, int grade);
        Bureaucrat(Bureaucrat const &other);
        Bureaucrat &operator=(Bureaucrat const &other);
        ~Bureaucrat();
        std::string const &getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
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

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);


#endif