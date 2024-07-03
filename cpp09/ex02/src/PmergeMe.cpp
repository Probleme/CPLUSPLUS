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

PmergeMe::PmergeMe(int ac, char **av)
{
    for (int i = 1; i < ac; ++i)
    {
        std::string arg = av[i];
        std::stringstream ss(arg);
        std::string num;
        ss >> num;
        int val = atoi(num.c_str());
        if (val < 0)
        {
            std::cerr << "Error: invalid argument" << std::endl;
            throw std::exception();
        }
        _vec.push_back(val);
        _lst.push_back(val);
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
        _lst = rhs._lst;
    }
    return *this;
}

std::vector<std::pair<int, int> > PmergeMe::getPairs(std::vector<int> &vec)
{
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < vec.size(); i += 2)
    {
        if (i + 1 < vec.size())
            pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
    }
    return pairs;
}

std::vector<std::pair<int, int> > PmergeMe::getLargestPair(std::vector<int> &vec)
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

void PmergeMe::mergeInsertSort(std::vector<std::pair<int, int> > &pairs)
{
    if (pairs.size() <= 1)
        return;
    std::vector<std::pair<int, int> >::iterator middle = pairs.begin() + pairs.size() / 2;
    std::vector<std::pair<int, int> > left(pairs.begin(), middle);
    std::vector<std::pair<int, int> > right(middle, pairs.end());
    mergeInsertSort(left);
    mergeInsertSort(right);
    pairs.clear();
    size_t left_index = 0;
    size_t right_index = 0;
    while (left_index < left.size() && right_index < right.size())
    {
        if (left[left_index].first <= right[right_index].first)
        {
            pairs.push_back(left[left_index]);
            left_index++;
        }
        else
        {
            pairs.push_back(right[right_index]);
            right_index++;
        }
    }
    while (left_index < left.size())
    {
        pairs.push_back(left[left_index]);
        left_index++;
    }
    while (right_index < right.size())
    {
        pairs.push_back(right[right_index]);
        right_index++;
    }
    // std::vector<std::pair<int, int> > tmp;
    // std::vector<std::pair<int, int> >::iterator it1 = left.begin();
    // std::vector<std::pair<int, int> >::iterator it2 = right.begin();
    // while (it1 != left.end() && it2 != right.end())
    // {
    //     if (it1->first < it2->first)
    //     {
    //         tmp.push_back(*it1);
    //         ++it1;
    //     }
    //     else
    //     {
    //         tmp.push_back(*it2);
    //         ++it2;
    //     }
    // }
    // tmp.insert(tmp.end(), it1, left.end());
    // tmp.insert(tmp.end(), it2, right.end());
    // pairs = tmp;
}

std::vector<int> PmergeMe::getVector() const
{
    return _vec;
}

std::list<int> PmergeMe::getList() const
{
    std::list<int> lst(_lst.begin(), _lst.end());
    return lst;
}
