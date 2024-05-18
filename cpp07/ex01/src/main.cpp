/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:51:41 by ataouaf           #+#    #+#             */
/*   Updated: 2024/05/18 10:21:12 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/iter.hpp"
#include <vector>

template <typename T>
void print(T &x)
{
    std::cout << x << std::endl;
}

int main()
{
    int tab[] = {0, 1, 2, 3, 4};
    ::iter(tab, sizeof(tab) / sizeof(*tab), print<int>);

    int tab2[] = {};
    ::iter(tab2, sizeof(tab2) / sizeof(*tab2), print<int>);

    std::string tab3[] = {"Hello", "World", "42"};
    ::iter(tab3, sizeof(tab3) / sizeof(*tab3), print<std::string>);

    int tab4[] = {0, 1, 2, 3, 4};
    ::iter(tab4, sizeof(tab4) / sizeof(*tab4), print<int>);

    return 0;
}
