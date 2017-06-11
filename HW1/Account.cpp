/*
 * Account.cpp
 *
 *  Created on: Jun 27, 2015
 *  Author: Gulsum Gudukbay
 *  Student ID: 21401148
 */

#include "Account.h"

Account::Account() {
	moneyAmount = 0.0;
}

Account::Account(double amount) {
	moneyAmount = amount;
}

double Account::getMoneyAmount() {
	return moneyAmount;
}

void Account::setAmount(double amount) {
	if (amount > 0)
		moneyAmount = amount;
	else
		moneyAmount = -1;
}

