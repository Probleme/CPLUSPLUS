/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:19:49 by ataouaf           #+#    #+#             */
/*   Updated: 2024/07/03 11:14:46 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: not enough arguments" << std::endl;
        return 1;
    }
    PmergeMe pmm(argc, argv);
    std::vector<std::pair<int, int> > pairs;
    std::vector<int> vec = pmm.getVector();
    std::list<int> lst = pmm.getList();
    pairs = pmm.getPairs(vec);
    pairs = pmm.getLargestPair(vec);
    std::cout << "Before: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    clock_t start = clock();
    pmm.mergeInsertSort(pairs);
    clock_t end = clock();
    for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
        std::cout << it->first << " " << it->second << std::endl;
    std::cout << "After: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << (double)(end - start) / CLOCKS_PER_SEC * 1e6 << " us" << std::endl;

    // start = clock();
    // pmm.mergeInsertSort(lst);
    // end = clock();
    // std::cout << "Time to process a range of " << lst.size() << " elements with std::list: " << (double)(end - start) / CLOCKS_PER_SEC * 1e6 << " us" << std::endl;

    return 0;
}
