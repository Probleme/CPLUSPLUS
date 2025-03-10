/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:50:58 by ataouaf           #+#    #+#             */
/*   Updated: 2024/06/09 10:08:23 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    try
    {
        std::cout << ::easyfind(v, 1) << std::endl;
        std::cout << ::easyfind(v, 42) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Element not found" << std::endl;
    }

    std::list<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);
    l.push_back(50);
    try
    {
        std::cout << ::easyfind(l, 30) << std::endl;
        std::cout << ::easyfind(l, 42) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Element not found" << std::endl;
    }

    std::deque<int> d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);
    d.push_back(5);
    try
    {
        std::cout << ::easyfind(d, 5) << std::endl;
        std::cout << ::easyfind(d, -42) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Element not found" << std::endl;
    }
    
    return 0;
}