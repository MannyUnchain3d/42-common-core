/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:08:52 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/22 20:36:55 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "Span.hpp"

/* ----- CONSTRUCTOR ------------------ */

/* Parameter Constructor */
Span::Span(unsigned int n) : _n(n) {}

/* Copy Constructor */
Span::Span(Span const& src) {
	*this = src;
}

/* ----- DESTRUCTOR ------------------- */

Span::~Span(void) {}

/* ----- OPERATOR OVERLOAD ------------ */

Span& Span::operator=(Span const& rhs) {
	if (this != &rhs) {
		this->_n = rhs._n;
		this->_list = rhs._list;
	}
	return (*this);
}

/* ----- PUBLIC METHOD ---------------- */

void Span::addNumber(int n) {
	if (_list.size() >= _n)
		throw std::out_of_range(CYAN "addNumber: " NC "list is full");
	_list.push_back(n);
}

void Span::addNumber(std::list<int>::const_iterator begin, std::list<int>::const_iterator end) {
	if (_list.size() >= _n)
		throw std::out_of_range(CYAN "addNumber: " NC "list is full");
	_list.insert(_list.end(), begin, end);
}

unsigned int	Span::shortestSpan(void) const {
	if (_list.empty())
		throw std::out_of_range("list is empty");
	else if (_list.size() == 1)
		throw std::out_of_range("list has only one element");

	std::list<int>	sortedList(_list);
	sortedList.sort();
	
	unsigned int	shortestSpan = std::numeric_limits<unsigned int>::max();
	
	std::list<int>::const_iterator it = sortedList.begin();
	std::list<int>::const_iterator nextIt = std::next(it);

	while (nextIt != sortedList.end()) {
		shortestSpan = std::min(shortestSpan, static_cast<unsigned int>(*nextIt - *it));
		++it;
		++nextIt;
	}
	return (shortestSpan);
}

unsigned int	Span::longestSpan(void) const {
	if (_list.empty())
		throw std::out_of_range("list is empty");
	else if (_list.size() == 1)
		throw std::out_of_range("list has only one element");
	return (*std::max_element(_list.begin(), _list.end()) - *std::min_element(_list.begin(), _list.end()));
}

std::list<int> const&	Span::getList(void) const {
	return (_list);
}

/* ----- OPERATOR OVERLOAD ------------ */

std::ostream&	operator<<(std::ostream& out, Span const& rhs) {
	for (std::list<int>::const_iterator it = rhs.getList().begin(); it != rhs.getList().end(); ++it)
		out << *it << " ";
	return (out);
}