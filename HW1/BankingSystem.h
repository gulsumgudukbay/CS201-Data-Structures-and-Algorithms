/*
 * BankingSystem.h
 *
 *  Created on: Jun 27, 2015
 *  Author: Gulsum Gudukbay
 *  Student ID: 21401148
 */

#ifndef BANKINGSYSTEM_H_
#define BANKINGSYSTEM_H_

#include "Account.h"
#include "Branch.h"
#include "Customer.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class BankingSystem {

public:
	BankingSystem();
	~BankingSystem();
	void addBranch(const int branchId, const string branchName);
	void deleteBranch(const int branchId);
	void addCustomer(const int customerId, const string customerName);
	void deleteCustomer(const int customerId);
	int addAccount(const int branchId, const int customerId,
			const double amount);
	void deleteAccount(const int accountId);
	void showAllAccounts();
	void showBranch(const int branchId);
	void showCustomer(const int customerId);
private:
	int accountCount;
	int specifyAccountId;
	int branchCount;
	int customerCount;
	int columnCount;

	Account *accountArr;
	Branch *branchArr;
	Customer *customerArr;

	int **indexArr;

};

#endif
