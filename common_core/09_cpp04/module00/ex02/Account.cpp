/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 02:21:14 by Manny             #+#    #+#             */
/*   Updated: 2023/07/05 04:31:56 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

/* Static attributes initialization */
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/* ----- CONSTRUCTOR ------------------ */

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts),
										_amount(initial_deposit),
										_nbDeposits(0),
										_nbWithdrawals(0) {
	Account::_nbAccounts++;
	Account::_totalAmount += _amount;
	_displayTimestamp();
	std::cout 	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "created" << std::endl;
	return ;
}

/* ----- DESTRUCTOR ------------------- */

Account::~Account(void) {
	Account::_nbAccounts--;
	_displayTimestamp();
	std::cout 	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "closed" << std::endl;
	return ;
}

/* ----- GETTERS ---------------------- */

/* Returns the number of existing accounts */
int	Account::getNbAccounts(void) {
	return (Account::_nbAccounts);
}

/* Returns the total amount in all accounts */
int	Account::getTotalAmount(void) {
	return (Account::_totalAmount);
}

/* Returns the total number of deposits */
int	Account::getNbDeposits(void) {
	return (Account::_totalNbDeposits);
}

/* Returns the total number of withdrawals */
int	Account::getNbWithdrawals(void) {
	return (Account::_totalNbWithdrawals);
}

/* ----- PRIVATE METHODS -------------- */

/* Displays the current date and time followed by a space.
 * Format: [YYYYMMDD_HHMMSS] */
void	Account::_displayTimestamp(void) {
	std::time_t	t = std::time(NULL);
	std::tm		*now = std::localtime(&t);

	std::cout << std::setfill('0') << "[" << now->tm_year + 1900
			  << std::setw(2) << now->tm_mon + 1
			  << std::setw(2) << now->tm_mday << "_"
			  << std::setw(2) << now->tm_hour
			  << std::setw(2) << now->tm_min
			  << std::setw(2) << now->tm_sec << "] " << std::flush;
}

/* ----- PUBLIC METHODS --------------- */

