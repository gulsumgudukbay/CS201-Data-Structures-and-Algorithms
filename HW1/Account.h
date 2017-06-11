/*
 * Account.h
 *
 *  Created on: Jun 27, 2015
 *  Author: Gulsum Gudukbay
 *  Student ID: 21401148
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

class Account {
public:
	Account();
	Account(double amount);

	//void operator=(const Account &right);
	double getMoneyAmount();
	void setAmount(double amount);

private:
	double moneyAmount;
};

#endif /* ACCOUNT_H_ */
