/*
 * Customer.cpp
 *
 *  Created on: Jun 27, 2015
 *  Author: Gulsum Gudukbay
 *  Student ID: 21401148
 */

#include "Customer.h"

Customer::Customer() {
	customerId = 0;
	customerName = "";
}

Customer::Customer(int id, string name) {
	customerId = id;
	customerName = name;
}

int Customer::getCustomerID() {
	return customerId;
}

string Customer::getCustomerName() {
	return customerName;
}

