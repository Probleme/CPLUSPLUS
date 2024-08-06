/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:19:49 by ataouaf           #+#    #+#             */
/*   Updated: 2024/07/03 11:14:46 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    try
    {
        PmergeMe pmm;
        pmm.launch(argc, argv);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: invalid argument" << std::endl;
        return 1;
    }
    
    return 0;
}
