/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:41:24 by ataouaf           #+#    #+#             */
/*   Updated: 2024/04/22 15:42:09 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default"){}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm(other), _target(other._target){}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
    if (this != &other)
    {
        _target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    srand(time(NULL));
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    if (!this->getSigned())
        throw AForm::FormNotSignedException();
    if (rand() % 2)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << _target << " robotomization failed" << std::endl;
}
