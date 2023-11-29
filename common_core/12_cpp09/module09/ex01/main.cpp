/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 23:02:09 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/29 23:35:01 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Usage: ./RPN \"[expression]\"" << std::endl;
        return (EXIT_FAILURE);
    }

    RPN rpn;
    rpn.calculate(av[1]);

    return (EXIT_SUCCESS);
}