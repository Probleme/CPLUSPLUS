/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:42:40 by ataouaf           #+#    #+#             */
/*   Updated: 2024/04/26 15:48:43 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Array.hpp"

int main()
{
    try
    {
        Array<int> a(5);
        Array<int> b(99);

        for (unsigned int i = 0; i < a.size(); i++)
            a[i] = i;
        for (unsigned int i = 0; i < b.size(); i++)
            b[i] = i;

        std::cout << "Array a: ";
        for (unsigned int i = 0; i < a.size(); i++)
            std::cout << a[i] << " ";
        std::cout << std::endl;

        std::cout << "Array b: ";
        for (unsigned int i = 0; i < b.size(); i++)
            std::cout << b[i] << " ";
        std::cout << std::endl;

        Array<int> c(a);

        std::cout << "Array c: ";
        for (unsigned int i = 0; i < c.size(); i++)
            std::cout << c[i] << " ";
        std::cout << std::endl;

        c = b;

        std::cout << "Array c: ";
        for (unsigned int i = 0; i < c.size(); i++)
            std::cout << c[i] << " ";
        std::cout << std::endl;

        Array<int> d(0);
        std::cout << "Array d: ";
        for (unsigned int i = 0; i < d.size(); i++)
            std::cout << d[i] << " ";
        std::cout << std::endl;

        Array<int> e(9);
        std::cout << "Array e: ";
        for (unsigned int i = 0; i < e.size(); i++)
            std::cout << e[i] << " ";
        std::cout << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

// int main()
// {
    
    // Array<int> a(5);
    // Array<int> b(5);

    // for (unsigned int i = 0; i < a.size(); i++)
    //     a[i] = i;
    // for (unsigned int i = 0; i < b.size(); i++)
    //     b[i] = i + 5;

    // std::cout << "Array a: ";
    // for (unsigned int i = 0; i < a.size(); i++)
    //     std::cout << a[i] << " ";
    // std::cout << std::endl;

    // std::cout << "Array b: ";
    // for (unsigned int i = 0; i < b.size(); i++)
    //     std::cout << b[i] << " ";
    // std::cout << std::endl;

    // Array<int> c(a);

    // std::cout << "Array c: ";
    // for (unsigned int i = 0; i < c.size(); i++)
    //     std::cout << c[i] << " ";
    // std::cout << std::endl;

    // c = b;

    // std::cout << "Array c: ";
    // for (unsigned int i = 0; i < c.size(); i++)
    //     std::cout << c[i] << " ";
    // std::cout << std::endl;

    // return 0;
// }