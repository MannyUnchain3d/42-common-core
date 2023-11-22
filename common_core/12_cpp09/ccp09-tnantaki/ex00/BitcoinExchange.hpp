#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <exception>
#include <limits>
#include <stdlib.h>	// for atof, isdigit ,etc...
#include <iomanip>	// for setprecision

# define BLACK	"\e[0;30m"
# define RED	"\e[0;31m"
# define GREEN	"\e[0;32m"
# define YELLOW	"\e[0;33m"
# define BLUE	"\e[0;34m"
# define PURPLE	"\e[0;35m"
# define CYAN	"\e[0;36m"
# define WHITE	"\e[0;37m"
# define RESET	"\e[0m"

typedef	std::map<std::string, float>	date_price_t;

enum month_e
{
	Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
};

struct date_num_t
{
	std::string	date;
	std::string	num;
};

class BTC
{
	private:
		date_price_t	_dataBase;
		std::string		_lowestDate;

		void	_setDataBase(const char* fileName);
		float	_getPrice(const std::string& date) const;
	public:
		// Orthodox Cononical Form
		BTC();
		BTC(BTC const& other);
		BTC&	operator=(BTC const& rhs);
		~BTC();

		// Member Function
		void	prtDataBase() const;
		void	evaluate(char* fileName) const;

		// Exception
		class NoDataBase : public std::exception {
			const char* what() const throw() {return "Error: there aren't database csv.";}
		};
		class CouldNotOpenFile : public std::exception {
			const char* what() const throw() {return "Error: could not open file.";}
		};
};

void	prtErrMsg(const std::string msg);
void	ft_strtirm(std::string& str, const char* set);
bool	ft_isdigit_str(const std::string& str);

#endif