/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:53:36 by ataouaf           #+#    #+#             */
/*   Updated: 2024/05/08 14:16:06 by ataouaf          ###   ########.fr       */
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
            std::cout << "C" << std::endl;
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
