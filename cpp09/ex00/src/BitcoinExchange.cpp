/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:05:17 by ataouaf           #+#    #+#             */
/*   Updated: 2024/06/28 13:16:08 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& dbFilename)
{
    std::ifstream file(dbFilename);
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string date;
        double price = 0.0;
        if (std::getline(ss, date, ',') && (ss >> price))
            _database[date] = price;
    }
    file.close();
}

void BitcoinExchange::processInput(const std::string& inputFilename)
{
    std::ifstream file(inputFilename);
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");
    std::string line;
    std::getline(file, line);
    if (line != "date | value" )
        throw std::runtime_error("Error: bad input file.");
    while (std::getline(file, line))
    {
        if (line == "date | value" || line == "" || line == " ")
        {
            std::cout << "Error: bad input => date | value" << std::endl;
            continue;
        }
        std::istringstream ss(line);
        std::string date, valueStr;
        if (std::getline(ss, date, '|') && std::getline(ss >> std::ws, valueStr))
        {
            if (!isValidDate(date))
            {
                if (date != "" && date != " ")
                    std::cout << "Error: bad input => " << date << std::endl;
                else
                    std::cout << "Error: bad input." << std::endl;
                continue;
            }
            if (!isValidValue(valueStr))
            {
                if (valueStr.find_first_not_of("0123456789.") != std::string::npos)
                    std::cout << "Error: not a positive number." << std::endl;
                else
                    std::cout << "Error: too large a number." << std::endl;
                continue;
            }
            ss.clear();
            ss.str(valueStr);
            double value;
            ss >> value;
            std::string closestDate = getClosestDate(date);
            double price = _database.at(closestDate);
            std::cout << date << " => " << valueStr << " = " <<  value * price << std::endl;
        }
        else if (valueStr.empty() && date != "")
            std::cout << "Error: bad input => " << date << std::endl;
    }
    file.close();
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
    std::istringstream ss(date);
    int year, month, day;
    char sep1, sep2;
    if (ss >> year >> sep1 >> month >> sep2 >> day && sep1 == '-' && sep2 == '-' && month >= 1 && month <= 12 && day >= 1 && day <= 31 && year >= 2009 && year <= 2022)
    {
        if (month == 2)
        {
            bool isLeap = false;
            if (year % 4 == 0)
            {
                if (year % 100 != 0) 
                    isLeap = true;
                else if (year % 400 == 0)
                    isLeap = true;
            }
            int maxDay = isLeap? 29 : 28;
            if (day > maxDay)
                return false; 
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            if (day > 30)
                return false;
        }
        
        return true;
    }
    return false;
}

bool BitcoinExchange::isValidValue(const std::string& value)
{
    std::istringstream ss(value);
    double val;
    if (ss >> val && val >= 0 && val <= 1000)
        return true;
    return false;
}

std::string BitcoinExchange::getClosestDate(const std::string& date)
{
    std::map<std::string, double>::iterator it = _database.lower_bound(date);
    if (it == _database.end() || (it != _database.begin() && it->first != date))
        --it;
    return it->first;
}

BitcoinExchange::~BitcoinExchange() {}
