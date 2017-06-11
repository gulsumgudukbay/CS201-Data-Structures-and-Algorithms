/*
 * BankingSystem.cpp
 *
 *  Created on: Jun 27, 2015
 *  Author: Gulsum Gudukbay
 *  Student ID: 21401148
 */

#include "BankingSystem.h"

BankingSystem::BankingSystem() {
	columnCount = 3;
	accountCount = 0;
	branchCount = 0;
	customerCount = 0;
	specifyAccountId = 1;

	indexArr = NULL;

	accountArr = NULL;
	branchArr = NULL;
	customerArr = NULL;
}

BankingSystem::~BankingSystem() {
	for (int i = 0; i < accountCount; i++)
		delete[] indexArr[i];
	delete[] indexArr;
	delete[] accountArr;
	delete[] customerArr;
	delete[] branchArr;
}

//Adds a branch with the user specified branch id and branch name by checking
//whether if the branch id is used by another branch
void BankingSystem::addBranch(const int branchId, const string branchName) {

	bool b = 0;
	for (int i = 0; (i < branchCount) && (b == 0); i++)
		if (branchArr[i].getBranchID() == branchId)
			b = 1;
	if (b != 1) {
		Branch addedBranch = Branch(branchId, branchName);
		if (branchArr == NULL) {
			branchArr = new Branch[1];
			branchArr[0] = addedBranch;
		} else {
			Branch *temp = new Branch[branchCount + 1];

			for (int i = 0; i < branchCount; i++)
				temp[i] = branchArr[i];
			temp[branchCount] = addedBranch;
			delete[] branchArr;
			branchArr = temp;

		}

		branchCount++;
		cout << "Branch " << branchId << " has been added!" << endl;

	} else
		cout << "Branch " << branchId << " already exists." << endl;
}

//deletes the user specified branch by checking whether if it exists or not
void BankingSystem::deleteBranch(const int branchId) {

	if (branchCount != 0) {

		bool b = 0;
		int found;
		for (int i = 0; (i < branchCount) && (b == 0); i++) {
			if (branchArr[i].getBranchID() == branchId) {
				b = 1;
				found = i;
			}
		}
		if (b == 1) {
			//deleting the branch from branch array
			Branch *temp = new Branch[branchCount - 1];

			for (int i = 0; i < found; i++)
				temp[i] = branchArr[i];
			for (int j = found + 1; j < branchCount; j++)
				temp[j - 1] = branchArr[j];
			delete[] branchArr;
			branchArr = temp;

			//deleting the accounts associated with the specified deleted branch
			for (int i = 0; i < accountCount; i++)
				if (indexArr[i][1] == found)
					deleteAccount(indexArr[i][0]);

			for (int i = 0; i < accountCount; i++)
				if (indexArr[i][1] > found)
					indexArr[i][1]--;

			branchCount--;
			cout << "Branch " << branchId << " has been deleted!" << endl;

		} else
			cout << "Branch " << branchId << " doesn't exist." << endl;

	} else
		cout << "Error! No branch exists in this banking system.";

}

//adds a customer with the user specifies customer id and customer name by checking
//whether if the customer id is used by another customer
void BankingSystem::addCustomer(const int customerId, const string customerName) {
	bool b = 0;

	for (int i = 0; (i < customerCount) && (b == 0); i++)
		if (customerArr[i].getCustomerID() == customerId)
			b = 1;
	if (b != 1) {

		Customer addedCustomer = Customer(customerId, customerName);
		if (customerArr == NULL) {
			customerArr = new Customer[1];
			customerArr[0] = addedCustomer;

		} else {
			Customer *temp = new Customer[customerCount + 1];
			for (int i = 0; i < customerCount; i++)
				temp[i] = customerArr[i];
			temp[customerCount] = addedCustomer;
			delete[] customerArr;
			customerArr = temp;
		}

		customerCount++;

		cout << "Customer " << customerId << " has been added!" << endl;
	} else
		cout << "Customer " << customerId << " already exists" << endl;
}

//deletes the user specified customer by checking whether if it exists or not
void BankingSystem::deleteCustomer(const int customerId) {

	if (customerCount != 0) {

		bool b = 0;
		int found;
		for (int i = 0; (i < customerCount) && (b == 0); i++) {
			if (customerArr[i].getCustomerID() == customerId) {
				b = 1;
				found = i;
			}
		}
		if (b == 1) {
			//deleting the customer from customer array
			Customer *temp = new Customer[customerCount - 1];

			for (int i = 0; i < found; i++)
				temp[i] = customerArr[i];
			for (int j = found + 1; j < customerCount; j++)
				temp[j - 1] = customerArr[j];
			delete[] customerArr;
			customerArr = temp;
			//deleting the accounts associated with the specified deleted customer
			for (int i = 0; i < accountCount; i++)
				if (indexArr[i][2] == found)
					deleteAccount(indexArr[i][0]);

			for (int i = 0; i < accountCount; i++)
				if (indexArr[i][2] > found)
					indexArr[i][2]--;

			customerCount--;

			cout << "Customer " << customerId << " has been deleted" << endl;

		}
	} else
		cout << "Error! No customer exists in this banking system." << endl;

}

//adds an account to the banking system to the specified branch and customer, returns -1 if the branch or
//customer doesn't exist, else returns the account id that is added
int BankingSystem::addAccount(const int branchId, const int customerId,
		const double amount) {
	bool isBranchIDFound = 0;
	bool isCustomerIDFound = 0;
	int branchIndex;
	int customerIndex;
	//Checking whether if the branch id and customer id is valid
	for (int i = 0; (i < branchCount) && (isBranchIDFound == 0); i++)
		if (branchArr[i].getBranchID() == branchId) {
			isBranchIDFound = 1;
			branchIndex = i;
		}
	for (int i = 0; (i < customerCount) && (isCustomerIDFound == 0); i++)
		if (customerArr[i].getCustomerID() == customerId) {
			isCustomerIDFound = 1;
			customerIndex = i;
		}

	if (isBranchIDFound == 1 && isCustomerIDFound == 1) {

		Account addedAccount(amount);
		//creates a new array with one more slot and copies the old one's elements and adds the last one

		if (accountArr == NULL) {
			accountArr = new Account[1];
			accountArr[0] = addedAccount;
			indexArr = new int*[1];
			indexArr[0] = new int[3];
			indexArr[0][0] = specifyAccountId;
			indexArr[0][1] = branchIndex;
			indexArr[0][2] = customerIndex;

		} else {

			Account *temp = new Account[accountCount + 1];

			for (int i = 0; i < accountCount; i++)
				temp[i] = accountArr[i];

			temp[accountCount] = addedAccount;
			delete[] accountArr;
			accountArr = temp;

			//adds a new account to the indexArr for the correct slots of customer id and branch id
			int **temp2 = new int*[accountCount + 1];
			for (int i = 0; i < accountCount + 1; i++)
				temp2[i] = new int[columnCount];

			//copying elements to the temp array
			for (int i = 0; i < accountCount; i++)
				for (int j = 0; j < columnCount; j++) {
					temp2[i][j] = indexArr[i][j];
				}

			//adding the last added account
			temp2[accountCount][0] = specifyAccountId + 1;
			temp2[accountCount][1] = branchIndex;
			temp2[accountCount][2] = customerIndex;

			for (int i = 0; i < accountCount; i++)
				delete[] indexArr[i];
			delete[] indexArr;

			indexArr = temp2;
		}

		++accountCount;

		specifyAccountId = accountCount;

		cout << "Account " << specifyAccountId << " added for customer "
				<< customerId << " at branch " << branchId << endl;

		return specifyAccountId;

	} else {
		if (isBranchIDFound == 0 && isCustomerIDFound == 1)
			cout << "Branch " << branchId << " does not exist\n" << endl;
		else
			cout << "Customer " << customerId << " does not exist\n" << endl;
	}
	return -1;

}

//deletes the user specified account
void BankingSystem::deleteAccount(const int accountId) {
	if (accountCount > 0) {
		bool found = 0;
		int indexFound;
		for (int i = 0; (i < accountCount) && (found == 0); i++) {
			if (indexArr[i][0] == accountId) {
				found = 1;
				indexFound = i;
			}
		}

		if (found == 1) {
			//deleting the account from the account array
			Account *temp = new Account[accountCount - 1];

			for (int i = 0; i < indexFound; i++)
				temp[i] = accountArr[i];
			for (int j = indexFound + 1; j < accountCount; j++)
				temp[j - 1] = accountArr[j];

			delete[] accountArr;
			accountArr = temp;

			//deleting the account associated with its customer and branch locations from the index array

			int **temp2 = new int*[accountCount - 1];
			for (int i = 0; i < accountCount - 1; i++)
				temp2[i] = new int[columnCount];

			for (int i = 0; i < indexFound; i++)
				for (int j = 0; j < columnCount; j++) {
					temp2[i][j] = indexArr[i][j];
				}
			for (int i = indexFound + 1; i < accountCount; i++)
				for (int j = 0; j < columnCount; j++) {
					temp2[i - 1][j] = indexArr[i][j];
				}
			for (int i = 0; i < accountCount; i++)
				delete[] indexArr[i];
			delete[] indexArr;
			indexArr = temp2;
			accountCount--;

			cout << "Account " << accountId << " has been deleted" << endl;

		} else
			cout << "Account " << accountId << " does not exist." << endl;
	} else
		cout << "Error! No accounts exist in the banking system\n" << endl;
}

//prints all the accounts
void BankingSystem::showAllAccounts() {
	if (accountCount != 0) {
		cout
				<< "\nAccount id\tBranch id\tBranch name\tCustomer id\tCustomer name\t\tBalance "
				<< endl;

		cout << fixed;
		cout << setprecision(2);

		for (int i = 0; i < accountCount; i++)
			cout << indexArr[i][0] << "\t\t"
					<< branchArr[(indexArr[i][1])].getBranchID() << "\t"
					<< "\t" << branchArr[(indexArr[i][1])].getBranchName()
					<< "\t" << "\t"
					<< customerArr[(indexArr[i][2])].getCustomerID() << "\t"
					<< "\t" << customerArr[(indexArr[i][2])].getCustomerName()
					<< "\t" << "\t" << accountArr[i].getMoneyAmount() << endl;
	} else
		cout << "No accounts exist in this banking system.\n" << endl;
}

//prints all the branches and their account status
void BankingSystem::showBranch(const int branchId) {
	bool isFound = 0;
	int branchIndex;
	int branchAccount = 0;
	for (int i = 0; (i < branchCount) && (isFound == 0); i++) {

		if (branchArr[i].getBranchID() == branchId) {
			isFound = 1;
			branchIndex = i;
		}

	}

	if (isFound == 1) {
		for (int i = 0; i < accountCount; i++)
			if (indexArr[i][1] == branchIndex)
				branchAccount++;
		cout << "\nBranch id: " << branchId << "  Branch name: "
				<< (branchArr[branchIndex]).getBranchName()
				<< "  Number of Accounts: " << branchAccount << endl;
		if (branchAccount > 0) {
			cout
					<< "Accounts at this branch: \nAccount id\tCustomer id\tCustomer name\tBalance"
					<< endl;
			cout << fixed;
			cout << setprecision(2);
			for (int i = 0; i < accountCount; i++) {
				if (indexArr[i][1] == branchIndex) {
					cout << indexArr[i][0] << "\t" << "\t"
							<< customerArr[(indexArr[i][2])].getCustomerID()
							<< "\t" << "\t"
							<< customerArr[(indexArr[i][2])].getCustomerName()
							<< "\t" << accountArr[i].getMoneyAmount() << endl;
				}
			}

		}
	} else
		cout << "\nBranch " << branchId << " does not exist." << endl;

}

//prints all the customers and their account status
void BankingSystem::showCustomer(const int customerId) {
	bool isFound = 0;
	int customerIndex;
	int customerAccount = 0;

	for (int i = 0; (i < accountCount) && (isFound == 0); i++) {
		if (customerArr[i].getCustomerID() == customerId) {
			isFound = 1;
			customerIndex = i;
		}
	}

	if (isFound == 1) {
		for (int i = 0; i < accountCount; i++)
			if (indexArr[i][2] == customerIndex)
				customerAccount++;

		cout << "\nCustomer id: " << customerId << "  Customer name: "
				<< (customerArr[customerIndex]).getCustomerName()
				<< "  Number of Accounts: " << customerAccount << endl;
		if (customerAccount > 0) {
			cout
					<< "Accounts of this customer: \nAccount id\tBranch id\tBranch name\tBalance "
					<< endl;

			cout << fixed;
			cout << setprecision(2);
			for (int i = 0; i < accountCount; i++) {
				if (indexArr[i][2] == customerIndex) {
					cout << indexArr[i][0] << "\t" << "\t"
							<< branchArr[(indexArr[i][1])].getBranchID()
							<< "\t" << "\t"
							<< branchArr[(indexArr[i][1])].getBranchName()
							<< "\t" << "\t" << accountArr[i].getMoneyAmount()
							<< endl;
				}
			}
			cout << endl;
		}
	} else
		cout << "Customer " << customerId << " does not exist.\n" << endl;
}

