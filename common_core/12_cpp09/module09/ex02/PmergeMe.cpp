/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:42:12 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/30 22:26:59 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* ----- TEMPLATE SPECIALIZATION ----- */

template <typename Container>
std::string getContainerName();

template <>
std::string getContainerName<std::vector<int> >() {
	return "vector<int>";
}

template <>
std::string getContainerName<std::deque<int> >() {
	return "deque<int>";
}
/* ----- CONSTRUCTOR ------------------ */

/* Default Constructor */
template <typename Container>
PmergeMe<Container>::PmergeMe(void) : _data(), _last(-1), _time(0) {}

/* Parameter Constructor */
template <typename Container>
PmergeMe<Container>::PmergeMe(char **data) : _data(), _last(-1), _time(0) {
	for (size_t i = 0; data[i]; i++) {
		if (!_isNumber(data[i])) 
			throw std::invalid_argument("Error");
		_data.push_back(_toInt(data[i]));
	}
}

/* Copy Constructor */
template <typename Container>
PmergeMe<Container>::PmergeMe(PmergeMe const& src) {
	_data = src._data;
}

/* ----- DESTRUCTOR ------------------- */
template <typename Container>
PmergeMe<Container>::~PmergeMe(void) {}

/* ----- OPERATOR OVERLOAD ------------ */
template <typename Container>
PmergeMe<Container>& PmergeMe<Container>::operator=(PmergeMe const& rhs) {
	if (this != &rhs) {
		_data = rhs._data;
		_last = rhs._last;
		_time = rhs._time;
	}
	return (*this);
}

/* ----- PUBLIC METHOD ---------------- */

template <typename Container>
void	PmergeMe<Container>::sort() {
	// Record the start time of the sorting process
	std::clock_t	start = std::clock();

	// Generate pairs from the input data
	pairVector	pairs = _createPairs(_data);
	// Generate insertion indexes using the Jacobsthal sequence
	intVector	insertIndexes = _createIndexes(_data.size());

	// If there are no pairs (input size is 0 or 1), just push the last element (if it exists) and return
	if (pairs.size() == 0) {
		_data.push_back(_last);
		_time = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC;
	return;
	}
	
	// Sort the pairs based on the first element of each pair
	_sortPairs(pairs);
	
	_data.clear();
	
	// Push the second element of the first pair (smallest element) to the data vector
	_data.push_back(pairs[0].second);

	// Push the first element of each pair to the data vector
	for (size_t i = 0; i < pairs.size(); i++)
		_data.push_back(pairs[i].first);
	
	// Insert elements from the pairs vector into the data vector based on the insertion indexes
	for (size_t i = 0; i < insertIndexes.size(); i++) {
		// Check if the index is within the bounds of the pairs vector
		if (size_t(insertIndexes[i] - 1) >= pairs.size())
			continue;
		// Find the correct position using binary search and insert the element
		int index = _binarySearch(pairs[insertIndexes[i] - 1].second);
		_data.insert(_data.begin() + index, pairs[insertIndexes[i] - 1].second);
	}		
	// If there is a last element, insert it into the data vector at the correct position
	if (_last != -1) {
		int	index = _binarySearch(_last);
		_data.insert(_data.begin() + index, _last);
	}
	// Record the time taken for the sorting process
	_time = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC;
}

template <typename Container>
void PmergeMe<Container>::print() const {
	for (size_t i = 0; i < _data.size(); i++)
		std::cout << _data[i] << " ";
	std::cout << std::endl;
}

template <typename Container>

void PmergeMe<Container>::printTime() const {
	std::cout 
			<< "Time to process a range of " << _data.size()
			<< " elements with std::" << getContainerName<Container>()
			<< " : " << std::fixed << std::setprecision(5) << _time << " us"
			<< std::endl;
}

/* ----- PRIVATE METHOD --------------- */

template <typename Container>
intVector	PmergeMe<Container>::_createIndexes(size_t size) {
	intVector	indexes;
	int			jacobsthalSequence[size + 1];

	jacobsthalSequence[0] = 0;
	jacobsthalSequence[1] = 1;
	int	lastJabobsthalNumber = 2;

	for (size_t i = 2; indexes.size() < size; i++) {
		// Generate the next Jacobsthal number
		jacobsthalSequence[i] = 2 * jacobsthalSequence[i - 1] + jacobsthalSequence[i - 2];
		// Push the Jacobsthal number to indexes vector (skip the first iteration)
		i != 2 ? indexes.push_back(jacobsthalSequence[i - 1]) : (void)0;
		// Push back the indexes between the last Jacobsthal number and the current one
		for (int j = jacobsthalSequence[i] - 1; j > lastJabobsthalNumber; j--)
			indexes.push_back(j);
		// Update the last Jacobsthal number
		lastJabobsthalNumber = jacobsthalSequence[i];
	}
	return (indexes);
}

template <typename Container>
typename PmergeMe<Container>::pairVector	PmergeMe<Container>::_createPairs(Container &data) {
	pairVector	pairs;

	// Handle odd-sized data by storing the last element in _last
	if (data.size() % 2 != 0) {
		_last = data.back();
		data.pop_back();
	}
	// Iterate through the data in pairs, swapping if needed, and create pairs
	for (size_t i = 0; i < data.size(); i += 2) {
		if (data[i] < data[i + 1])
			std::swap(data[i], data[i + 1]);
		pairs.push_back(std::make_pair(data[i], data[i + 1]));
	}
	return (pairs);
}

template <typename Container>
void	PmergeMe<Container>::_sortPairs(pairVector &pairs) {
	if (pairs.size() <= 1)
		return;
	// Calculate the middle index and create two vectors
	sizeType	middle = pairs.size() / 2;
	pairVector	left(pairs.begin(), pairs.begin() + middle);
	pairVector	right(pairs.begin() + middle, pairs.end());
	// Recursively call _sortPairs on the left and right vectors
	_sortPairs(left);
	_sortPairs(right);
	// Merge the sorted left and right vectors into the original vector
	sizeType	leftIndex = 0;
	sizeType	rightIndex = 0;
	sizeType	Index = 0;
	// Compare the first elements of the left and right vectors
    // Place the smaller one in the original vector
	while (leftIndex < left.size() && rightIndex < right.size())
		pairs[Index++] = (left[leftIndex].first < right[rightIndex].first) ? left[leftIndex++] : right[rightIndex++];
	// Add any remaining elements in the left and right vectors to the original vector
	while (leftIndex < left.size())
		pairs[Index++] = left[leftIndex++];
	
	while (rightIndex < right.size())
		pairs[Index++] = right[rightIndex++];
}

template <typename Container>
int	PmergeMe<Container>::_binarySearch(int target) {
	// Initialize left and right indices for the binary search
	int	left = 0;
	int	right = _data.size() - 1;

	while (left <= right) {
		// Calculate the middle index
		int	middle = (left + right) / 2;
		// Check if the middle element is equal to the target
		if (_data[middle] == target)
			return (middle);
		else if (_data[middle] < target)
			left = middle + 1; // If the middle element is smaller than the target, search the right half
		else
			right = middle - 1; // If the middle element is larger than the target, search the left half
	}
	return (left);
}

template <typename Container>
int	PmergeMe<Container>::_toInt(char const *str) {
	std::stringstream	ss(str);
	int					number;

	ss >> number;
	return (number);
}

template <typename Container>
bool	PmergeMe<Container>::_isNumber(std::string const& str) {
	if (str.empty() || str[0] == '-')
		return (false);

	size_t	i = 0;
	
	if (str[i] == '+' && str.size()== 1)
		return (false);
	else if (str[i] == '+')
		i++;

	for (; i < str.length(); i++) {
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

template class PmergeMe< std::vector<int> >;
template class PmergeMe< std::deque<int> >;