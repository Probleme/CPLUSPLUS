/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:10:31 by ataouaf           #+#    #+#             */
/*   Updated: 2023/11/11 23:47:05 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

bool replaceFunc(std::string filename, std::string s1, std::string s2)
{
	std::ifstream file(filename.c_str());
	if (!file.good()) {
		std::cerr << "Error" << std::endl << "Cannot open file `" << filename
			<< "' for reading." << std::endl;
		return false;
	}

	std::ofstream outfile(filename.append(".replace").c_str());
	std::string str;

	while (s1.length() && std::getline(file, str)) {
		int idx = str.find(s1, 0);
		while (idx != -1) {
			str.erase(idx, s1.length());
			str.insert(idx, s2);
			idx += s2.length();
			idx = str.find(s1, idx);
		}
		outfile << str << std::endl;
	}
	return true;
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Error: wrong number of arguments" << std::endl;
        return (1);
    }
    if (!replaceFunc(argv[1], argv[2], argv[3]))
    {
        std::cout << "Error: cannot open file" << std::endl;
        return (1);
    }
    return (0);
}