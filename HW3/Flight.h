/*
 * Flight.h
 *
 *  Created on: Jul 16, 2015
 *  Author: Gulsum Gudukbay
 *  Student ID: 21401148
 */

#ifndef FLIGHT_H_
#define FLIGHT_H_

#include <string>
#include <iostream>
using namespace std;


class Flight {
public:

	struct Passenger {
		string firstName;
		string lastName;
		Passenger *pNext;
	};

	Flight(const int flightId, const string fromCity, const string toCity);
	~Flight();
	bool doesPassengerExist(const string firstName, const string lastName)const;
	void displayPassengers()const ;
	bool addPassenger(const string firstName, const string lastName);
	bool removePassenger(const string firstName, const string lastName);
	void removeFromBeginning();
	Flight* getFNext();
	int getFlightId();
	void setFPrev(Flight* newFPrev);
	void setFNext(Flight* newFNext);
	string getFromCity();
	string getToCity();

private:

	int flightId;
	string fromCity;
	string toCity;
	Passenger* pHead;
	Flight* fPrev;
	Flight* fNext;
};

#endif /* FLIGHT_H_ */
