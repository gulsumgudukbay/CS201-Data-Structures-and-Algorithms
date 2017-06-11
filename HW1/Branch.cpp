/*
 * Branch.cpp
 *
 *  Created on: Jun 27, 2015
 *  Author: Gulsum Gudukbay
 *  Student ID: 21401148
 */

#include "Branch.h"

Branch::Branch() {
	branchId = 0;
	branchName = "";
}

Branch::Branch(int id, string name) {
	branchId = id;
	branchName = name;
}

int Branch::getBranchID() {
	return branchId;
}

string Branch::getBranchName() {
	return branchName;
}
