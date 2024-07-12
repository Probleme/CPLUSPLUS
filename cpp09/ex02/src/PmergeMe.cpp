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
        std::list<int >::iterator it = std::upper_bound(_sorted_deque.begin(), _sorted_deque.end(), pairs[i].second);
        _sorted_deque.insert(it, pairs[i].second);
    }
    if (_sorted_deque.size() % 2)
    {
        std::list<int >::iterator it = std::upper_bound(_sorted_deque.begin(), _sorted_deque.end(), pairs[pairs.size() - 1].second);
        _sorted_deque.insert(it, pairs[pairs.size() - 1].second);
    }
}

void PmergeMe::mergeInsertSortVec(std::vector<std::pair<int, int> > &pairs)
{
    if (pairs.size() <= 1)
        return;
    std::sort(pairs.begin(), pairs.end());
    for (size_t i = 0; i < pairs.size(); ++i)
        _sorted_vec.push_back(pairs[i].first);
    std::vector<int> jacob_vec;
    jacobSthal(jacob_vec, pairs.size());
    _sorted_vec.insert(_sorted_vec.begin(), pairs[0].second);
    std::cout << "Beforeeee: ";
    for (std::vector<int>::iterator it = _sorted_vec.begin(); it != _sorted_vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "vector pairs second: ";
    for (size_t i = 0; i < pairs.size(); i++)
        std::cout << pairs[i].second << " ";
    std::cout << std::endl;
    for (size_t i = 1; i < jacob_vec.size(); i++)
    {
        for (int j = jacob_vec[i]; j > jacob_vec[i - 1]; --j)
        {
            std::vector<int >::iterator it = std::upper_bound(_sorted_vec.begin(), _sorted_vec.end(), pairs[j].second);
            _sorted_vec.insert(it, pairs[j].second);
            std::cout << "Inserting " << pairs[j].second << std::endl;
        }
        // std::vector<int >::iterator it = std::upper_bound(_sorted_vec.begin(), _sorted_vec.end(), pairs[i].second);
        // _sorted_vec.insert(it, pairs[i].second);
    }
    if (_sorted_vec.size() % 2)
    {
        std::vector<int >::iterator it = std::upper_bound(_sorted_vec.begin(), _sorted_vec.end(), pairs[pairs.size() - 1].second);
        _sorted_vec.insert(it, pairs[pairs.size() - 1].second);
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

void PmergeMe::jacobSthal(std::vector<int> &jacob, int nbr)
{
    if (nbr == 0)
        return;
    jacob.push_back(0);
    if (nbr == 1)
        return;
    jacob.push_back(1);
    for (int i = 2; ; i++)
    {
        int tmp = jacob[i - 1] + 2 * jacob[i - 2];
        if (tmp <= nbr)
        {
            jacob.push_back(tmp);
        }
        else
            return;
    }
}
