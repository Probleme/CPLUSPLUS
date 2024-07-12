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
#include <deque>
#include <iterator>

class PmergeMe
{
    private:
        std::vector<int> _vec;
        std::deque<int> _deque;
        std::vector<int> _sorted_vec;
        std::deque<int> _sorted_deque;
    public:
        PmergeMe();
        PmergeMe(PmergeMe const &src);
        ~PmergeMe();
        void launch(int ac, char **av);
        PmergeMe &operator=(PmergeMe const &rhs);
        std::vector<std::pair<int, int> > makePairVect(std::vector<int> &vec);
        std::deque<std::pair<int, int> > makePairDeque(std::deque<int> &deque);
        void mergeInsertSortVec(std::vector<std::pair<int, int> > &pairs);
        void mergeInsertSortDeque(std::deque<std::pair<int, int> > &pairs);
        void jacobSthal(std::vector<int> &jacob, int nbr);
        
        std::vector<int> getVector() const;
        std::deque<int> getDeque() const;
};

#endif