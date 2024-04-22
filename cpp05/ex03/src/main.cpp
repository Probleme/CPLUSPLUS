/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:46:38 by ataouaf           #+#    #+#             */
/*   Updated: 2024/04/22 16:13:34 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/Intern.hpp"

int main()
{
    try
    {
        Intern someRandomIntern;
        Bureaucrat b("Bureaucratyes", 1);
        AForm *rrf;
        AForm *scf;
        AForm *ppf;
        AForm *notFound;

        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        scf = someRandomIntern.makeForm("shrubbery creation", "Bender1");
        ppf = someRandomIntern.makeForm("presidential pardon", "Bender2");
        notFound = someRandomIntern.makeForm("something else", "Bender3");
        try
        {
            b.signForm(*rrf);
            b.executeForm(*rrf);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        try
        {
            b.executeForm(*scf);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        try
        {
            b.executeForm(*ppf);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }      
        delete rrf;
        delete scf;
        delete ppf;

        delete notFound;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}