/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:46:38 by ataouaf           #+#    #+#             */
/*   Updated: 2024/04/22 13:25:41 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main()
{
    try
    {
        Bureaucrat b1("b1", 1);
        Bureaucrat b2("b2", 150);
        Form f1("f1", 1, 1);
        Form f2("f2", 150, 150);
        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
        b1.decrementGrade();
        b2.incrementGrade();
        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        b1.signForm(f1);
        b2.signForm(f2);
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}