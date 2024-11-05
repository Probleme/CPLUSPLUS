/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:23:22 by ataouaf           #+#    #+#             */
/*   Updated: 2024/11/04 12:07:24 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

void PmergeMe::launch(int ac, char **av)
{
    clock_t start = clock();
    for (int i=1; i < ac; ++i)
    {
        std::string arg = av[i];
        std::stringstream ss(arg);
        int val;
        if (!(ss >> val))
            throw std::runtime_error("Error : cannot convert to int.");
        if (val < 0)
            throw std::runtime_error("Error");
        _vec.push_back(val);
    }
    std::cout << "Before: ";
    for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::vector<std::pair<int, int> > pairs_vec = makePairVect(_vec);
    mergeInsertSortVec(pairs_vec);
    clock_t end = clock();

    clock_t start2 = clock();
    for (int i=1; i < ac; ++i)
    {
        std::string arg = av[i];
        std::stringstream ss(arg);
        int val;
        if (!(ss >> val))
            throw std::runtime_error("Error : cannot convert to int.");
        if (val < 0)
            throw std::runtime_error("Error");
        _deque.push_back(val);
    }
    
    std::deque<std::pair<int, int> > pairs_deque = makePairDeque(_deque);
    mergeInsertSortDeque(pairs_deque);
    
    std::cout << "After: ";
    for (std::deque<int>::iterator it = _sorted_deque.begin(); it != _sorted_deque.end(); ++it)
        std::cout << *it << " ";
    clock_t end2 = clock();
    std::cout << std::endl;
    std::cout << "Time to process a range of " << _vec.size() 
                  << " elements with std::vector: " 
                  << static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000 
                  << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size() 
                  << " elements with std::deque: " 
                  << static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000000 
                  << " us" << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
    *this = src;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
    if (this != &rhs)
    {
        _vec = rhs._vec;
        _deque = rhs._deque;
        _sorted_vec = rhs._sorted_vec;
        _sorted_deque = rhs._sorted_deque;
    }
    return *this;
}

std::vector<std::pair<int, int> > PmergeMe::makePairVect(std::vector<int> &vec)
{
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < vec.size(); i += 2)
    {
        if (i + 1 < vec.size())
        {
            if (vec[i] > vec[i + 1])
                pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
            else
                pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
        }
    }
    return pairs;
}

std::deque<std::pair<int, int> > PmergeMe::makePairDeque(std::deque<int> &deque)
{
    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < deque.size(); i += 2)
    {
        if (i + 1 < deque.size())
        {
            if (deque[i] > deque[i + 1])
                pairs.push_back(std::make_pair(deque[i], deque[i + 1]));
            else
                pairs.push_back(std::make_pair(deque[i + 1], deque[i]));
        }
    }
    return pairs;
}

void PmergeMe::mergeInsertSortDeque(std::deque<std::pair<int, int> > &pairs)
{
    if (_deque.size() <= 1)
    {
        _sorted_deque = _deque;
        return;
    }
    std::sort(pairs.begin(), pairs.end());
    for (size_t i = 0; i < pairs.size(); ++i)
        _sorted_deque.push_back(pairs[i].first);
    _sorted_deque.insert(_sorted_deque.begin(), pairs[0].second);
    for (size_t i = 1; i < pairs.size(); i++)
    {
        std::deque<int >::iterator it = std::upper_bound(_sorted_deque.begin(), _sorted_deque.end(), pairs[i].second);
        _sorted_deque.insert(it, pairs[i].second); 
    }
    if (_deque.size() % 2)
    {
        std::deque<int >::iterator it = std::upper_bound(_sorted_deque.begin(), _sorted_deque.end(), _deque.back());
        _sorted_deque.insert(it, _deque.back());
    }
}

void PmergeMe::mergeInsertSortVec(std::vector<std::pair<int, int> > &pairs)
{
    if (_vec.size() <= 1)
    {
        _sorted_vec = _vec;
        return;
    }
    std::sort(pairs.begin(), pairs.end());
    for (size_t i = 0; i < pairs.size(); ++i)
        _sorted_vec.push_back(pairs[i].first);
    _sorted_vec.insert(_sorted_vec.begin(), pairs[0].second);
    for (size_t i = 1; i < pairs.size(); i++)
    {
        std::vector<int >::iterator it = std::upper_bound(_sorted_vec.begin(), _sorted_vec.end(), pairs[i].second);
        _sorted_vec.insert(it, pairs[i].second);
    }
    if (_vec.size() % 2 == 1)
    {
        std::vector<int >::iterator it = std::upper_bound(_sorted_vec.begin(), _sorted_vec.end(), _vec.back());
        _sorted_vec.insert(it, _vec.back());
    }
}