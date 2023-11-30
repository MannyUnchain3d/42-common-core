/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:44:16 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/30 18:51:48 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av) {
    if (ac < 2) {
        std::cout << "Usage: " << av[0] << "[int] [int] [int] ..." << std::endl;
        return EXIT_FAILURE;
    }
    
    try {
        PmergeMe<std::vector<int> > v(av + 1);
        
        std::cout << "Before:\t";
        v.print();

        v.sort();

        PmergeMe<std::deque<int> > d(av + 1);
        
        d.sort();
        
        std::cout << "After:\t";
        d.print();

        v.printTime();
        d.printTime();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return EXIT_SUCCESS;
}
