/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:04:31 by ataouaf           #+#    #+#             */
/*   Updated: 2024/05/16 15:09:44 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other)
{
    *this = other;
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        _stack = other._stack;
    return *this;
}

RPN::RPN(const std::string& input)
{
    std::istringstream iss(input);
    std::string token;

    while (iss >> token)
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (_stack.size() < 2)
                throw std::runtime_error("Error: invalid expression");

            int operand2 = _stack.top();
            _stack.pop();
            int operand1 = _stack.top();
            _stack.pop();

            int result;
            if (token == "+")
                result = operand1 + operand2;
            else if (token == "-")
                result = operand1 - operand2;
            else if (token == "*")
                result = operand1 * operand2;
            else
            {
                if (operand2 == 0)
                    throw std::runtime_error("Error: division by zero");
                result = operand1 / operand2;
            }
            _stack.push(result);
        }
        else
        {
            std::istringstream iss(token);
            int operand;
            if (!(iss >> operand))
                throw std::runtime_error("Error: invalid expression");
            _stack.push(operand);
        }
    }
    if (_stack.size() != 1)
        throw std::runtime_error("Error: invalid expression");
}

void RPN::printResult() const
{
    std::cout << _stack.top() << std::endl;
}