/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:15:19 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/20 21:46:49 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

/* ----- CONSTRUCTOR ------------------ */

/* Default Constructor */
template <typename T>
Array<T>::Array() : _elements(NULL), _arraySize(0) {}

/* Parameter Constructor */
template <typename T>
Array<T>::Array(unsigned int n) : _arraySize(n) {
    _elements = new T[_arraySize];
    for (unsigned int i = 0; i < _arraySize; ++i) 
        _elements[i] = T();
}

/* Copy Constructor */
template <typename T>
Array<T>::Array(Array const & src) : _arraySize(src._arraySize) {
   _elements = new T[_arraySize];
    for (unsigned int i = 0; i < _arraySize; ++i) 
          _elements[i] = src._elements[i];
}

/* ----- DESTRUCTOR ------------------- */

template <typename T>
Array<T>::~Array() {
    delete[] _elements;
}

/* ----- OPERATOR OVERLOAD ------------ */

/* Assignment Operator */
template <typename T>
Array<T>& Array<T>::operator=(Array const & src) {
    if (this != &src) {
        delete[] _elements;
        _arraySize = src._arraySize;
        _elements = new T[_arraySize];
        for (unsigned int i = 0; i < _arraySize; ++i) 
            _elements[i] = src._elements[i];
    }
    return *this;
}

/* Subscript Operator */
template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _arraySize)
        throw Array<T>::OutOfRangeException();
    return _elements[index];
}

/* ----- PUBLIC METHOD ---------------- */

/* Size Method */
template <typename T>
unsigned int    Array<T>::size() const {
    return _arraySize;
}

/* Print Method */
template <typename T>
void    Array<T>::print() const {
    for (unsigned int i = 0; i < _arraySize; ++i)
        std::cout << _elements[i] << " ";
    std::cout << std::endl;
}

/* ----- EXCEPTIONS ------------------- */

/* OutOfRangeException */
template <typename T>
const char* Array<T>::OutOfRangeException::what() const throw() {
    return ("Array index is out of range");
}
