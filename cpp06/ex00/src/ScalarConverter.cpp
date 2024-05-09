/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:28:07 by ataouaf           #+#    #+#             */
/*   Updated: 2024/05/08 13:24:16 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
    *this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &)
{
    return *this;
}

ScalarConverter::~ScalarConverter() {}

bool isMixed(const std::string &str)
{
    bool hasDigit = false;
    bool hasAlpha = false;
    int countF = 0;
    int countDot = 0;
    int countPlus = 0;
    char c;

    if (str == "inf" || str == "-inf" || str == "+inf" || str == "inff" || str == "-inff" || str == "+inff" || str == "nan" || str == "nanf")
        return false;
    for (size_t i = 0; i < str.size(); i++)
    {
        c = str[i];
        if (std::ispunct(c) && str.size() > 1 && c != '.' && c != '+' && c != '-')
            return true;
        if (std::isdigit(c))
            hasDigit = true;
        else if (std::isalpha(c) && c != 'f')
            hasAlpha = true;
        if (hasDigit && hasAlpha)
            return true;
        if (c == 'f')
            countF++;
        if (c == '.')
            countDot++;
        if (c == '+')
            countPlus++;
    }
    if (countF == 1 && str.back() != 'f')
        return true;
    if (countF > 1 || countDot > 1 || countPlus > 1 || str.back() == '.')
        return true;
    return false;
}

void ScalarConverter::convert(const std::string &str)
{
    if (str[0] == '.' && str.size() > 1)
    {
        std::string tmp = "0" + str;
        ScalarConverter::convert(tmp);
        return;
    }
    if (isMixed(str))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << "nanf" << std::endl;
        std::cout << "double: " << "nan" << std::endl;
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
    iss.clear();
    iss.str(str);
    std::cout << "float: ";
    std::string strValue = iss.str();
    if (str == "inff" || str == "-inff" || str == "+inff" || (str.back() == 'f' && str != "nanf" && str != "inf" && str != "-inf" && str != "+inf"))
        strValue = strValue.substr(0, strValue.size() - 1);
    iss.clear();
    iss.str(strValue);
    float f;
    if (iss >> f || f != 0)
        std::cout << f << (f - static_cast<int>(f) == 0 ? ".0f" : "f") << std::endl;
    else if (str.size() == 1 && !std::isdigit(str[0]))
        std::cout << static_cast<int>(str[0]) << ".0f" << std::endl;
    else
        std::cout << "nanf" << std::endl;
    std::cout << "double: ";
    iss.clear();
    iss.str(str);
    strValue.clear();
    strValue = iss.str();
    if (str == "inff" || str == "-inff" || str == "+inff" || (str.back() == 'f' && str != "nanf" && str != "inf" && str != "-inf" && str != "+inf"))
        strValue = strValue.substr(0, strValue.size() - 1);
    iss.clear();
    iss.str(strValue);
    double d;
    if (iss >> d || d != 0)
        std::cout << d << (d - static_cast<int>(d) == 0 ? ".0" : "") << std::endl;
    else if (str.size() == 1 && !std::isdigit(str[0]))
        std::cout << static_cast<int>(str[0]) << ".0" << std::endl;
    else
        std::cout << "nan" << std::endl;
}
