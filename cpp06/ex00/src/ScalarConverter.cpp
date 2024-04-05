/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:28:07 by ataouaf           #+#    #+#             */
/*   Updated: 2024/04/05 16:44:03 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(const std::string &str)
{
    std::cout << "char: ";
    try
    {
        int i = std::stoi(str);
        if (i < 32 || i > 126)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "impossible" << std::endl;
    }
    std::cout << "int: ";
    try
    {
        int i = std::stoi(str);
        std::cout << i << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "impossible" << std::endl;
    }
    std::cout << "float: ";
    try
    {
        float f = std::stof(str);
        std::cout << f << std::endl;
        if (f - static_cast<int>(f) == 0)
            std::cout << f << ".0f" << std::endl;
        else
            std::cout << f << "f" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "nanf" << std::endl;
    }
    std::cout << "double: ";
    try
    {
        double d = std::stod(str);
        if (d - static_cast<int>(d) == 0)
            std::cout << d << ".0" << std::endl;
        else
            std::cout << d << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "nan" << std::endl;
    }
}
