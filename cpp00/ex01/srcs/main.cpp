/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:33:51 by ataouaf           #+#    #+#             */
/*   Updated: 2023/10/20 03:41:44 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

int main(void) {
    PhoneBook phoneBook;
    std::string command;
    std::cout << "Welcome to your phonebook!\n";
    std::cout << "The available commands are `ADD`, `SEARCH` and `EXIT`.\n";
    std::cout << "> ";
    while (std::getline(std::cin, command) && command != "EXIT") {
        if (command == "ADD")
        {
            if (!phoneBook.addContact())
                break;
        }
        else if (command == "SEARCH")
            phoneBook.searchContact();
        else
            std::cerr << "Wrong input, the available commands are `ADD`, `SEARCH`"
                " and `EXIT`. You should try again.\n";
        std::cout << "> ";
    }
    return 0;
}