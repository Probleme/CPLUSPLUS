/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:23:22 by ataouaf           #+#    #+#             */
/*   Updated: 2024/07/03 12:36:17 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe() {}


void PmergeMe::launch(int ac, char **av)
{
    for (int i=1; i < ac; ++i)
    {
        std::string arg = av[i];
        std::stringstream ss(arg);
        int val;
        if (!(ss >> val))
        {
            std::cerr << "Error: invalid argument" << std::endl;
            throw std::exception();
        }
        if (val < 0)
        {
            std::cerr << "Error: invalid argument" << std::endl;
            throw std::exception();
        }
        _vec.push_back(val);
        _deque.push_back(val);
    }
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
    if (pairs.size() <= 1)
        return;
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
    if (pairs.size() <= 1)
        return;
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
    std::cout << "After: ";
    for (std::vector<int>::iterator it = _sorted_vec.begin(); it != _sorted_vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

std::vector<int> PmergeMe::getVector() const
{
    return _vec;
}

std::deque<int> PmergeMe::getDeque() const
{
    return _deque;
}