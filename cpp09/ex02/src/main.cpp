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
    PmergeMe pmm;
    std::cout << "Before: ";
    clock_t start = clock();
    pmm.launch(argc, argv);
    std::vector<int> vec = pmm.getVector();
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::vector<std::pair<int, int> > pairs_vec;
    pairs_vec = pmm.makePairVect(vec);
    pmm.mergeInsertSortVec(pairs_vec);
    clock_t end = clock();;
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << (double)(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << std::endl;
    
    clock_t start2 = clock();
    std::deque<int> deque = pmm.getDeque();
    std::deque<std::pair<int, int> > pairs_deque = pmm.makePairDeque(deque);
    pmm.mergeInsertSortDeque(pairs_deque);
    clock_t end2 = clock();
    std::cout << "Time to process a range of " << deque.size() << " elements with std::deque: " << (double)(end2 - start2) / CLOCKS_PER_SEC * 1000 << " ms" << std::endl;
    return 0;
}
