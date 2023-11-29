/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:14:24 by Manny             #+#    #+#             */
/*   Updated: 2023/11/29 22:08:56 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Usage: ./bitcoin [filename]" << std::endl;
        return (EXIT_FAILURE);
    }
    
    BitcoinExchange exchange;
    
    exchange.extract(av[1]);
    
    return (EXIT_SUCCESS);
}
