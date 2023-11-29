/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 23:02:29 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/29 23:38:25 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>
# include <sstream>
# include <cmath>

class RPN {
	public:
		RPN(void);
		RPN(RPN const& src);
		~RPN(void);

		RPN& operator=(RPN const& rhs);

		void 	calculate(std::string input);


	private:
		std::stack<int>	_stack;
		
		typedef int (RPN::*func)(int, int);
		struct ops {
			std::string	op;
			func 		f;
		};
		
		ops	_ops[4];
		
		int	_mul(int a, int b);
		int	_div(int a, int b);
		int	_add(int a, int b);
		int	_sub(int a, int b);
	
		int	_indexOf(std::string str, std::string *arr, int size);
		int	_toInt(std::string const& str);
		std::string	_isAllDigit(std::string const& str, int (*isDigit)(int));
};

#endif
