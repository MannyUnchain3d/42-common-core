/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 23:02:15 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/29 23:37:43 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* ----- CONSTRUCTOR ------------------ */

/* Default Constructor */
RPN::RPN(void) {
	this->_ops[0].op = "*";
	this->_ops[0].f = &RPN::_mul;
	this->_ops[1].op = "/";
	this->_ops[1].f = &RPN::_div;
	this->_ops[2].op = "+";
	this->_ops[2].f = &RPN::_add;
	this->_ops[3].op = "-";
	this->_ops[3].f = &RPN::_sub;
}

/* Copy Constructor */
RPN::RPN(RPN const& src) {
	*this = src;
}

/* ----- DESTRUCTOR ------------------- */

RPN::~RPN(void) {}

/* ----- OPERATOR OVERLOAD ------------ */

RPN& RPN::operator=(RPN const& rhs) {
	if (this != &rhs)
		this->_stack = rhs._stack;
	return (*this);
}

/* ----- PUBLIC METHOD ---------------- */

void RPN::calculate(std::string input) {
	std::stringstream	ss(input);
	std::string	operators[] = {"*", "/", "+", "-"};

	try {
		while (ss >> input) {
			int	index = this->_indexOf(input, operators, 4);
			if (index != -1) {
				if (this->_stack.size() < 2)
					throw std::invalid_argument("Not enough operands");
				int	a = this->_stack.top();
				this->_stack.pop();
				int	b = this->_stack.top();
				this->_stack.pop();
				
				this->_stack.push((this->*_ops[index].f)(b, a)); 
			}
			else
				this->_stack.push(this->_toInt(this->_isAllDigit(input, &std::isdigit)));
		}
		if (this->_stack.size() != 1)
			throw std::invalid_argument("Too many operands");
		
		std::cout << this->_stack.top() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error" << std::endl;
	}
	ss.clear();
}

/* ----- PRIVATE METHOD --------------- */

int	RPN::_mul(int a, int b) {
	return (a * b);
}

int	RPN::_div(int a, int b) {
	if (b == 0)
		throw std::invalid_argument("Division by zero");
	return (a / b);
}

int	RPN::_add(int a, int b) {
	return (a + b);
}

int	RPN::_sub(int a, int b) {
	return (a - b);
}

int	RPN::_indexOf(std::string str, std::string *arr, int size) {
	for (int i = 0; i < size; i++) {
		if (str == arr[i])
			return (i);
	}
	return (-1);
}

int	RPN::_toInt(std::string const& str) {
	std::stringstream	ss(str);
	int					n;

	ss >> n;
	
	if (ss.fail())
		throw std::invalid_argument("Conversion error");
	return (n);
}

std::string	RPN::_isAllDigit(std::string const& str, int (*isDigit)(int)) {
	bool	isDigitBool = true;
	size_t	i 			= 0;

	if (str.length() == 1 && (str[0] == '-' || str[0] == '+'))
		isDigitBool = false;

	if (str.length() == 0)
		isDigitBool = false;
	
	if (str[0] == '-' || str[0] == '+')
		i = 1;
	
	for (; i < str.length(); i++) {
		if (!isDigit(str[i]))
			isDigitBool = false;
	}
	if (!isDigitBool)
		throw std::invalid_argument("Not a number");
	return (str);
}

