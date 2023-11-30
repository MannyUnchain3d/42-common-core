/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:42:16 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/30 19:09:43 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <iomanip>
# include <sstream>
# include <ctime>

typedef std::vector<int> intVector;

template<typename Container>
class PmergeMe {
	public:
		PmergeMe(void);
		explicit PmergeMe(char **data);
		PmergeMe(PmergeMe const& src);
		~PmergeMe(void);

		PmergeMe& operator=(PmergeMe const& rhs);

		typedef typename Container::value_type 		valueType;
		typedef typename Container::size_type		sizeType;
		typedef std::pair <valueType, valueType>	pairType;
		typedef std::vector <pairType>				pairVector;	

		void	sort();
		void	print() const;
		void	printTime() const;
	
	private:
		Container	_data;
		valueType	_last;
		double		_time;

		intVector	_createIndexes(size_t n);
		pairVector	_createPairs(Container &data);
		void		_sortPairs(pairVector &pairs);
		int			_binarySearch(int target);
		int			_toInt(char const *str);
		bool		_isNumber(std::string const &str);
};

#endif
