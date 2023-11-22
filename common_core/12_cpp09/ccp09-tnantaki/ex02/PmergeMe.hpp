#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>		// atol()
#include <iomanip>		// std::setprecision
#include <limits>		// MAX_INT
#include <cstring>		// strlen()
#include <sys/time.h>	// gettimeofday()

# define BLACK	"\e[0;30m"
# define RED	"\e[0;31m"
# define GREEN	"\e[0;32m"
# define YELLOW	"\e[0;33m"
# define BLUE	"\e[0;34m"
# define PURPLE	"\e[0;35m"
# define CYAN	"\e[0;36m"
# define WHITE	"\e[0;37m"
# define RESET	"\e[0m"

struct pair_t
{
	unsigned int	first, second;
};

// mergeInsertionSort
void	mergeInsertSort(std::vector<unsigned int> & nums);
void	mergeInsertSort(std::deque<unsigned int> & nums);
// Library Function
void	prtErrMsg(const std::string msg);
void	prtArr(unsigned int* arr, size_t n);
bool	setInput(unsigned int* & arr, size_t size, char **av);
double	getExecTime(struct timeval & start);

void	displayNum(std::vector<unsigned int> const & nums, std::string const & str);
void	displayNum(std::deque<unsigned int> const & nums, std::string const & str);
void	checkAscending(std::vector<unsigned int> const & nums, std::string str);
void	checkAscending(std::deque<unsigned int> const & nums, std::string str);

#endif