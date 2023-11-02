/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:10:31 by ataouaf           #+#    #+#             */
/*   Updated: 2023/10/22 20:12:20 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Error: wrong number of arguments" << std::endl;
        return (1);
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::ifstream ifs(filename);
    if (!ifs)
    {
        std::cout << "Error: can't open file" << std::endl;
        return (1);
    }
    std::ofstream ofs(filename + ".replace");
    if (!ofs)
    {
        std::cout << "Error: can't create file" << std::endl;
        return (1);
    }
    std::string line;
    while (std::getline(ifs, line))
    {
        while (line.find(s1) != std::string::npos)
            line.replace(line.find(s1), s1.length(), s2);
        ofs << line << std::endl;
    }
    ifs.close();
    ofs.close();
    return (0);
}