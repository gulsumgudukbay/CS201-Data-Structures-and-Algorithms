/*
 * Branch.h
 *
 *  Created on: Jun 27, 2015
 *  Author: Gulsum Gudukbay
 *  Student ID: 21401148
 */

#ifndef BRANCH_H_
#define BRANCH_H_

#include <string>
using namespace std;


class Branch {
public:
	Branch();
	Branch(int branchId, string branchName);

	string showBranch();
	int getBranchID();
	string getBranchName();


private:
	int branchId;
	string branchName;
};

#endif /* BRANCH_H_ */
