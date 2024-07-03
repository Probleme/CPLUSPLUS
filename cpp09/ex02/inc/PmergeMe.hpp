/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:23:30 by ataouaf           #+#    #+#             */
/*   Updated: 2024/07/03 10:09:33 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>
#include <time.h>
#include <sstream>

class PmergeMe
{
    private:
        std::vector<int> _vec;
        std::list<int> _lst;
    public:
        PmergeMe();
        PmergeMe(int ac, char **av);
        PmergeMe(PmergeMe const &src);
        ~PmergeMe();
        PmergeMe &operator=(PmergeMe const &rhs);
        std::vector<std::pair<int, int> > getPairs(std::vector<int> &vec);
        std::vector<std::pair<int, int> > getLargestPair(std::vector<int> &vec);
        void mergeInsertSort(std::vector<std::pair<int, int> > &pairs);
        
        std::vector<int> getVector() const;
        std::list<int> getList() const;
};

#endif