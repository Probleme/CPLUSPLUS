/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:05:26 by ataouaf           #+#    #+#             */
/*   Updated: 2024/10/29 11:49:47 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>


class BitcoinExchange
{
    private:
        std::map<std::string, double> _database;
        std::string _inputDate;
    public:
        BitcoinExchange(const std::string& dbFilename);
        ~BitcoinExchange();
        void processInput(const std::string& inputFilename);
        bool isValidDate(const std::string& date);
        std::string getClosestDate(const std::string& date);
};


#endif