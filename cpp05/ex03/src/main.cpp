/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:46:38 by ataouaf           #+#    #+#             */
/*   Updated: 2024/03/05 17:14:47 by ataouaf          ###   ########.fr       */
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
        Bureaucrat b("Bureaucrat", 1);
        AForm *rrf;
        AForm *scf;
        AForm *ppf;

        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
        ppf = someRandomIntern.makeForm("presidential pardon", "Bender");

        b.signForm(*rrf);
        b.executeForm(*rrf);
        b.signForm(*scf);
        b.executeForm(*scf);
        b.signForm(*ppf);
        b.executeForm(*ppf);        
        delete rrf;
        delete scf;
        delete ppf;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}