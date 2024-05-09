/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:29:37 by ataouaf           #+#    #+#             */
/*   Updated: 2024/05/08 12:11:43 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

int main(int ac, char **av)
{
    (void)av;
    if (ac != 2)
    {
        std::cout << "Usage: ./convert [value]" << std::endl;
        return 1;
    }
    ScalarConverter::convert(av[1]);
    return 0;
}
