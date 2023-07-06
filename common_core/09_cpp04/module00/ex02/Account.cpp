/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 02:21:14 by Manny             #+#    #+#             */
/*   Updated: 2023/07/06 21:06:42 by etetopat         ###   ########.fr       */
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

/* ----- PUBLIC METHODS --------------- */

/* Makes a deposit of the specified amount into the account.
 * Updates the amount of deposits and the total amount of deposits.
 * Prints the account information before and after the deposit. */
void	Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout 	<< "index:" << _accountIndex << ";"
				<< "p_amount:" << _amount << ";"
				<< "deposit:";
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout	<< deposit << ";"
				<< "amount:" << _amount << ";"
				<< "nb_deposits:" << _nbDeposits << std::endl;
}

/* Makes a withdrawal of the specified amount from the account.
 * Updates the amount of withdrawals and the total amount of withdrawals.
 * Prints the account information before and after the withdrawal.
 * If the withdrawal is not possible, prints "refused" instead of the amount. */
bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout 	<< "index:" << _accountIndex << ";"
				<< "p_amount:" << _amount << ";"
				<< "withdrawal:";
	if (withdrawal > _amount) {
		std::cout << "refused" << std::endl;
		return (false);
	}
	else {
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout	<< withdrawal << ";"
					<< "amount:" << _amount << ";"
					<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
	}
	return (true);
}

/* Prints the amount of the current account. */
int		Account::checkAmount(void) const {
	return (_amount);
}

/* Displays the status of the current account. */
void	Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout 	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "deposits:" << _nbDeposits << ";"
				<< "withdrawals:" << _nbWithdrawals << std::endl;
}

/* Displays the status of all the accounts. */
void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout 	<< "accounts:" << getNbAccounts() << ";"
				<< "total:" << getTotalAmount() << ";"
				<< "deposits:" << getNbDeposits() << ";"
				<< "withdrawals:" << getNbWithdrawals() << std::endl;
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