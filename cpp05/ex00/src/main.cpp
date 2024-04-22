/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:46:38 by ataouaf           #+#    #+#             */
/*   Updated: 2024/04/22 13:11:13 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("b1", 1);
        std::cout << b1 << std::endl;
        b1.decrementGrade();
        std::cout << b1 << std::endl;
        b1.incrementGrade();
        std::cout << b1 << std::endl;
        b1.decrementGrade();
        std::cout << b1 << std::endl;
        b1.incrementGrade();
        std::cout << b1 << std::endl;
        b1.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b2("b2", 150);
        std::cout << b2 << std::endl;
        b2.incrementGrade();
        std::cout << b2 << std::endl;
        b2.decrementGrade();
        std::cout << b2 << std::endl;
        b2.incrementGrade();
        std::cout << b2 << std::endl;
        b2.decrementGrade();
        std::cout << b2 << std::endl;
        b2.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b3("b3", 0);
        std::cout << b3 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b4("b4", 151);
        std::cout << b4 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}