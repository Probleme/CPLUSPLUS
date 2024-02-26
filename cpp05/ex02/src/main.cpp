/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:46:38 by ataouaf           #+#    #+#             */
/*   Updated: 2024/02/26 20:27:08 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

int main()
{
    Bureaucrat b1("Bureaucrat1", 1);
    Bureaucrat b2("Bureaucrat2", 150);
    PresidentialPardonForm f1("target1");
    RobotomyRequestForm f2("target2");
    ShrubberyCreationForm f3("target3");

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
    std::cout << f3 << std::endl;

    try
    {
        b2.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        b1.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        b1.signForm(f1);
        b1.executeForm(f1);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        b1.signForm(f2);
        b1.executeForm(f2);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        b1.signForm(f3);
        b1.executeForm(f3);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}