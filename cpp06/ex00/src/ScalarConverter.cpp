/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:28:07 by ataouaf           #+#    #+#             */
/*   Updated: 2024/04/25 16:13:22 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

bool isMixed(const std::string &str) {
    bool hasDigit = false;
    bool hasAlpha = false;
    int countF = 0;
    int countDot = 0;
    char c;

    for (size_t i = 0; i < str.size(); i++)
    {
        c = str[i];
        if (std::isdigit(c) && c != '.')
            hasDigit = true;
        else if (std::isalpha(c) && c != 'f')
            hasAlpha = true;
        if (hasDigit && hasAlpha)
            return true;
        if (c == 'f')
            countF++;
        if (c == '.')
            countDot++;
    }
    if (countF > 1 || countDot > 1 || str.back() == '.')
        return true;
    if (str.back() == 'f' && countDot == 0)
        return true;
    return false;
}

void ScalarConverter::convert(const std::string &str)
{
    if (isMixed(str))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }
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
    {
        if (str.size() == 1)
        {
            if (std::isdigit(str[0]))
                std::cout << "impossible" << std::endl;
            else
                std::cout << "'" << str[0] << "'" << std::endl;
        }
        else
            std::cout << "impossible" << std::endl;
    }
    else
    {
        if (i < 32 || i > 126)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
    }
    std::cout << "int: ";
    iss.clear();
    iss.str(str);
    if (!(iss >> i))
    {
        if (str.size() == 1)
        {
            if (!std::isdigit(str[0]))
                std::cout << static_cast<int>(str[0]) << std::endl;
            else
                std::cout << "impossible" << std::endl;
        }
        else
            std::cout << "impossible" << std::endl;
    }
    else
        std::cout << (i) << std::endl;
    std::cout << "float: ";
    iss.clear();
    iss.str(str);
    float f;
    iss >> f;
    std::string strValue = iss.str();
    if (strValue.find("f") != std::string::npos)
        strValue = strValue.substr(0, strValue.size() - 1);
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
