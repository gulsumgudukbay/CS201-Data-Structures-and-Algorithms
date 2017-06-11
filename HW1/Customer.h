/*
 * Customer.h
 *
 *  Created on: Jun 27, 2015
 *  Author: Gulsum Gudukbay
 *  Student ID: 21401148
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>
using namespace std;

class Customer {
public:
	Customer();
	Customer(int id, string name);
	string getCustomerName();
	int getCustomerID();

private:

	int customerId;
	string customerName;
};

#endif /* CUSTOMER_H_ */
