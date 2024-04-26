/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:53:36 by ataouaf           #+#    #+#             */
/*   Updated: 2024/04/25 16:09:47 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

Base *generate(void)
{
    int randomNumber = rand() % 3;
    switch (randomNumber)
    {
    case 0:
        return new A();
    case 1:
        return new B();
    case 2:
        return new C();
    }
    return nullptr;
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown Type" << std::endl;
}

void identify(Base &p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch (std::bad_cast &bc)
    {
        try
        {
            B &b = dynamic_cast<B &>(p);
            (void)b;
            std::cout << "B" << std::endl;
        }
        catch (std::bad_cast &bc)
        {
            try
            {
                C &c = dynamic_cast<C &>(p);
                (void)c;
                std::cout << "C" << std::endl;
            }
            catch (std::bad_cast &bc)
            {
                std::cout << "Unknown Type" << std::endl;
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    Base *base = generate();
    identify(base);
    identify(*base);
    delete base;
    return 0;
}