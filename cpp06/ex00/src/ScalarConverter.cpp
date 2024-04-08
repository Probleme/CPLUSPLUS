/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:28:07 by ataouaf           #+#    #+#             */
/*   Updated: 2024/04/07 17:38:38 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &str)
{
    if (str == "inff" || str == "-inff" || str == "+inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << str << std::endl;
        std::cout << "double: " << str.substr(0, str.size() - 1) << std::endl;
        return;
    }
    else if (str == "inf" || str == "-inf" || str == "+inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << str << "f" << std::endl;
        std::cout << "double: " << str << std::endl;
        return;
    }
    std::cout << "char: ";
    std::istringstream iss(str);
    int i;
    if (!(iss >> i))
        std::cout << "impossible" << std::endl;
    else
    {
        if (i < 32 || i > 126)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
    }
    std::cout << "int: ";
    iss.clear(); // Clear any error flags
    iss.str(str); // Reset stream with the original input string
    if (!(iss >> i)) 
        std::cout << "impossible" << std::endl;
    else
        std::cout << i << std::endl;
    std::cout << "float: ";
    iss.clear();
    iss.str(str);
    float f;
    iss >> f;
    std::string strValue = iss.str();
    if (strValue.find("f") != std::string::npos)
        strValue = strValue.substr(0, strValue.size() - 1);
    // now we need to clear the stream and reset it with strValue
    iss.clear();
    iss.str(strValue);
    if (!(iss >> f))
        std::cout << "nanf" << std::endl;
    else
        std::cout << f << (f - static_cast<int>(f) == 0 ? ".0f" : "f") << std::endl;
    std::cout << "double: ";
    iss.clear();
    iss.str(str);
    double d;
    iss >> d;
    strValue.clear();
    strValue = iss.str();
    if (strValue.find("f") != std::string::npos)
        strValue = strValue.substr(0, strValue.size() - 1);
    iss.clear();
    iss.str(strValue);
    if (!(iss >> d))
        std::cout << "nan" << std::endl;
    else
        std::cout << d << (d - static_cast<int>(d) == 0 ? ".0" : "") << std::endl;
}
