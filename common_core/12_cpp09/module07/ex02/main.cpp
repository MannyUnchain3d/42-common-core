/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:36:24 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/21 15:04:11 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.tpp"
#include "colors.h"

int main() {
    // Test for Array of Integers
    std::cout << GREEN << "#----- ARRAY OF INT -------#" << NC << std::endl;
    {
        Array<int> intArray(5);

        try {
            // Writing to the array
            for (unsigned int i = 0; i < intArray.size(); ++i)
                intArray[i] = static_cast<int>(i);

            // Reading from the array and printing
            intArray.print();

            // Accessing an out-of-range element (should throw exception)
            std::cout << "Attempting to access an out-of-range element: ";
            std::cout << intArray[intArray.size()] << std::endl;
        } catch (std::exception &e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    }
    std::cout << std::endl;

    // Test for Array of Floats
    std::cout << YELLOW << "#----- ARRAY OF FLOAT -----#" << NC << std::endl;
    {
        Array<float> floatArray(5);

        try {
            // Writing to the array
            for (unsigned int i = 0; i < floatArray.size(); ++i)
                floatArray[i] = i * 3.0f;

            // Reading from the array and printing
            floatArray.print();

            // Accessing an out-of-range element (should throw exception)
            std::cout << "Attempting to access an out-of-range element: ";
            std::cout << floatArray[floatArray.size()] << std::endl;
        } catch (std::exception &e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    }
    std::cout << std::endl;

    // Test for Array of Strings
    std::cout << BLUE << "#----- ARRAY OF STRING ----#" << NC << std::endl;
    {
        Array<std::string> strArray(2);

        try {
            // Writing to the array
            strArray[0] = "HELLO";
            strArray[1] = "WORLD";

            // Reading from the array and printing
            strArray.print();

            // Accessing an out-of-range element (should throw exception)
            std::cout << "Attempting to access an out-of-range element: ";
            std::cout << strArray[strArray.size()] << std::endl;
        } catch (std::exception &e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    }
    std::cout << std::endl;

    // Test for Array of Doubles
    std::cout << RED << "#----- ARRAY OF DOUBLE ----#" << NC << std::endl;
    {
        Array<double> dblArray(0);

        try {
        // Accessing an in-range element
        dblArray[0] = 42.42;
        std::cout << "Element at index 0: " << dblArray[0] << std::endl;

        // Accessing an out-of-range element (should throw exception)
        std::cout << "Attempting to access an out-of-range element: ";
        std::cout << dblArray[1] << std::endl;
        } catch (std::exception &e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    }

    return 0;
}
