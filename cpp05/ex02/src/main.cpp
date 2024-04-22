/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:46:38 by ataouaf           #+#    #+#             */
/*   Updated: 2024/04/22 16:16:59 by ataouaf          ###   ########.fr       */
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
        b1.signForm(f1);
        b1.signForm(f1);
        b1.executeForm(f1);
        b1.signForm(f2);
        b1.executeForm(f2);
        b1.signForm(f3);
        b1.executeForm(f3);
        b2.signForm(f1);
        b2.executeForm(f1);
        b2.signForm(f2);
        b2.executeForm(f2);
        b2.signForm(f3);
        b2.executeForm(f3);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}