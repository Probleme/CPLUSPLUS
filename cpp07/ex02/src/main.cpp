/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:42:40 by ataouaf           #+#    #+#             */
/*   Updated: 2024/05/14 10:21:43 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Array.hpp"

int main()
{
    try
    {
        Array<int> a(5);
        Array<int> b(101);

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

        std::cout << "Array b: ";
        for (unsigned int i = 0; i < b.size(); i++)
            std::cout << b[i] << " ";
        std::cout << std::endl;
        
        std::cout << "Array a: ";
        for (unsigned int i = 0; i < a.size(); i++)
            std::cout << a[i] << " ";
        std::cout << std::endl;

        Array<int> d(9);
        std::cout << "Array d: ";
        for (unsigned int i = 0; i < d.size(); i++)
            std::cout << d[i] << " ";
        std::cout << std::endl;

        Array<std::string> f(3);
        f[0] = "Hello";
        f[1] = "World";
        f[2] = "!";
        std::cout << "Array f: ";
        for (unsigned int i = 0; i < f.size(); i++)
            std::cout << f[i] << " ";
        std::cout << std::endl;
        
        Array<char> g(3);
        g[0] = 'H';
        g[1] = 'e';
        g[2] = 'y';
        std::cout << "Array g: ";
        for (unsigned int i = 0; i < g.size(); i++)
            std::cout << g[i] << " ";
        std::cout << std::endl;

        Array<float> h(3);
        h[0] = 1.1;
        h[1] = 2.2;
        h[2] = 3.3;
        std::cout << "Array h: ";
        for (unsigned int i = 0; i < h.size(); i++)
            std::cout << h[i] << " ";
        std::cout << std::endl;

        Array<int> e(-1);
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
