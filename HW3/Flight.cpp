/*
 * Flight.cpp
 *
 *  Created on: Jul 16, 2015
 *  Author: Gulsum Gudukbay
 *  Student ID: 21401148
 */

#include "Flight.h"

//initializes a flight and its passenger list
Flight::Flight(const int flightId, const string fromCity, const string toCity) {

	this-> flightId = flightId;
	this-> fromCity = fromCity;
	this-> toCity = toCity;
	pHead = NULL;
	fPrev = NULL;
	fNext = NULL;

}

//deletes all the passengers in a flight
Flight::~Flight() {

	while (pHead != NULL)
		removeFromBeginning();

}

//adds a passenger to a flight if it doesn't exist
bool Flight::addPassenger(const string firstName, const string lastName) {

	if (!doesPassengerExist(firstName, lastName)) {
		Passenger* addedPassenger = new Passenger;
		addedPassenger->firstName = firstName;
		addedPassenger->lastName = lastName;
		if (pHead == NULL) {
			pHead = addedPassenger;
			addedPassenger->pNext = NULL;

		} else {
			addedPassenger->pNext = pHead;
			pHead = addedPassenger;

		}
		return true;
	} else
		return false;

}

//removes from the beginning, used in the destructor
void Flight::removeFromBeginning() {
	if (pHead != NULL) {
		Passenger *cur;
		cur = pHead;
		pHead = pHead->pNext;
		cur->pNext = NULL;
		delete cur;
		cur = NULL;
	}
}

//removes a specified passenger
bool Flight::removePassenger(const string firstName, const string lastName) {

	if (doesPassengerExist(firstName, lastName)) {
		Passenger *cur = pHead;
		Passenger *prev = pHead;

		if ((pHead->firstName).compare(firstName) == 0
				&& (pHead->firstName).compare(lastName)) {
			pHead = pHead->pNext;
			delete cur;
			cur = NULL;
		} else {

			while (cur->pNext != NULL && (cur->firstName).compare(firstName)
					!= 0 && (cur->lastName).compare(lastName) != 0) {
				prev = cur;
				cur = cur->pNext;
			}

			if (cur->pNext == NULL && (cur->firstName).compare(firstName) == 0
					&& (cur->lastName).compare(lastName) == 0) {
				delete cur;
				prev->pNext = NULL;
			} else if (cur->pNext != NULL
					&& (cur->firstName).compare(firstName) == 0
					&& (cur->lastName).compare(lastName) == 0) {
				prev->pNext = cur->pNext;
				delete cur;
				cur = NULL;
			}
		}
		return true;
	} else
		return false;
}

//returns the next flight of a flight
Flight* Flight::getFNext() {
	return fNext;
}

//sets the previous flight of a flight
void Flight::setFPrev(Flight* newFPrev) {
	fPrev = newFPrev;
}
//sets the next flight of a flight
void Flight::setFNext(Flight* newFNext) {
	fNext = newFNext;
}

//returns the flight id of a flight
int Flight::getFlightId() {
	return flightId;
}

//returns the from city of a flight
string Flight::getFromCity() {
	return fromCity;
}

//returns the to city of a flight
string Flight::getToCity() {
	return toCity;
}

//displays all the passengers of a flight
void Flight::displayPassengers() const {
	if (pHead != NULL) {
		for (Passenger *cur = pHead; cur != NULL; cur = cur->pNext)
			cout << cur->firstName << " " << cur->lastName << endl;
	} else
		cout << "No passenger exists in this flight." << endl;

}

//checks whether if a passenger exists of not, returns true if it exists
bool Flight::doesPassengerExist(const string firstName, const string lastName) const {
	//search for the given name and last name
	bool exists = false;
	Passenger* temp = pHead;
	while (temp != NULL && !exists) {
		if ((temp->firstName).compare(firstName) == 0
				&& (temp->lastName).compare(lastName) == 0)
			exists = true;
		temp = temp->pNext;
	}
	temp = NULL;
	return exists;
}
