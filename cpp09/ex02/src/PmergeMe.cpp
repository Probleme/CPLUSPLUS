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
    clock_t start = clock();
    for (int i=1; i < ac; ++i)
    {
        std::string arg = av[i];
        std::stringstream ss(arg);
        int val;
        if (!(ss >> val))
            throw std::exception();
        if (val < 0)
            throw std::exception();
        _vec.push_back(val);
    }
    std::cout << "Before: ";
    for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::vector<std::pair<int, int> > pairs_vec = makePairVect(_vec);
    mergeInsertSortVec(pairs_vec);

    std::cout << "After: ";
    for (std::vector<int>::iterator it = _sorted_vec.begin(); it != _sorted_vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    clock_t end = clock();
    std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector: " << (double)(end - start) / CLOCKS_PER_SEC * 1000000 << " us" << std::endl;
    
    clock_t start2 = clock();
    for (int i=1; i < ac; ++i)
    {
        std::string arg = av[i];
        std::stringstream ss(arg);
        int val;
        ss >> val;
        _deque.push_back(val);
    }
    std::deque<std::pair<int, int> > pairs_deque = makePairDeque(_deque);
    mergeInsertSortDeque(pairs_deque);
    clock_t end2 = clock();
    std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque: " << (double)(end2 - start2) / CLOCKS_PER_SEC * 1000000 << " us" << std::endl;
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
    if (_deque.size() <= 1)
        return;
    std::sort(pairs.begin(), pairs.end());
    for (size_t i = 0; i < pairs.size(); ++i)
        _sorted_deque.push_back(pairs[i].first);
    std::deque<int> jacob;
    jacobSthalDeque(jacob, pairs.size());
    jacob.erase(jacob.begin(), jacob.begin() + 2);
    std::deque<int> res_index;
    combinIndex(jacob, res_index);
    _sorted_deque.insert(_sorted_deque.begin(), pairs[0].second);
    for (size_t i = 0; res_index[i]; i++)
    {
        if (res_index[i] >= (int)pairs.size())
            continue;
        std::deque<int >::iterator it = std::upper_bound(_sorted_deque.begin(), _sorted_deque.end(), pairs[res_index[i]].second);
        _sorted_deque.insert(it, pairs[res_index[i]].second); 
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
        return;
    std::sort(pairs.begin(), pairs.end());
    for (size_t i = 0; i < pairs.size(); ++i)
        _sorted_vec.push_back(pairs[i].first);
    std::vector<int> jacob;
    jacobSthalVec(jacob, pairs.size());
    jacob.erase(jacob.begin(), jacob.begin() + 2);
    std::vector<int> res_index;
    combinIndex(jacob, res_index);
    _sorted_vec.insert(_sorted_vec.begin(), pairs[0].second);
    for (size_t i = 0; res_index[i]; i++)
    {
        if (res_index[i] >= (int)pairs.size())
            continue;
        std::vector<int >::iterator it = std::upper_bound(_sorted_vec.begin(), _sorted_vec.end(), pairs[res_index[i]].second);
        _sorted_vec.insert(it, pairs[res_index[i]].second);
    }
    if (_vec.size() % 2 == 1)
    {
        std::vector<int >::iterator it = std::upper_bound(_sorted_vec.begin(), _sorted_vec.end(), _vec.back());
        _sorted_vec.insert(it, _vec.back());
    }
}

void PmergeMe::combinIndex(std::vector<int> &Jsequence, std::vector<int> &res_index)
{
    int i = 0;
    int j = Jsequence.size() - 1;
    int k = 0;
    while (i <= Jsequence[j])
    {
        if (i == Jsequence[k])
        {
            int y = i;
            while (k >= 1 && y != Jsequence[k - 1])
            {
                res_index.push_back(y - 1);
                y--;
            }
            k++;
        }
        i++;
    }
}

void PmergeMe::combinIndex(std::deque<int> &Jsequence, std::deque<int> &res_index)
{
    int i = 0;
    int j = Jsequence.size() - 1;
    int k = 0;
    while (i <= Jsequence[j])
    {
        if (i == Jsequence[k])
        {
            int y = i;
            while (k >= 1 && y != Jsequence[k - 1])
            {
                res_index.push_back(y - 1);
                y--;
            }
            k++;
        }
        i++;
    }
}

void PmergeMe::jacobSthalVec(std::vector<int> &jacob, int nbr)
{
    jacob.push_back(0);
    jacob.push_back(1);
    for (int i = 2; jacob[jacob.size() - 1] < nbr; i++)
    {
        if (i % 2 == 0)
            jacob.push_back(2 * jacob[i - 1] - 1);
        else
            jacob.push_back(2 * jacob[i - 1] + 1);
    }
}

void PmergeMe::jacobSthalDeque(std::deque<int> &jacob, int nbr)
{
    jacob.push_back(0);
    jacob.push_back(1);
    for (int i = 2; jacob[jacob.size() - 1] < nbr; i++)
    {
        if (i % 2 == 0)
            jacob.push_back(2 * jacob[i - 1] - 1);
        else
            jacob.push_back(2 * jacob[i - 1] + 1);
    }
}
