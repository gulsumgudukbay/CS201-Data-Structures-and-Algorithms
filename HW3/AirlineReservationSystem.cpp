/*
 * AirlineReservationSystem.cpp
 *
 *  Created on: Jul 16, 2015
 *  Author: Gulsum Gudukbay
 *  Student ID: 21401148
 */

#include "AirlineReservationSystem.h"

//constructor, initializes an empty flight list
AirlineReservationSystem::AirlineReservationSystem() {
	fHead = NULL;
}

//destructor, deletes all the flights
AirlineReservationSystem::~AirlineReservationSystem() {
	while (fHead != NULL) {
		Flight *current;
		current = fHead;
		fHead = (*fHead).getFNext();
		(*current).setFNext(NULL);
		delete current;
		current = NULL;
	}

}

//tells wheter if the flight exists or not, if it exists, returns true
bool AirlineReservationSystem::isFlightFound(const int id) const {
	//search for the given flightId
	bool exists = false;
	Flight* temp = fHead;
	while (temp != NULL) {
		if ((*temp).getFlightId() == id)
			exists = true;
		temp = (*temp).getFNext();
	}

	return exists;
}

//returns the flight that is situated just before the id of the flight specified
Flight* AirlineReservationSystem::traverseToFlight(const int id) const {

	Flight* current = fHead;

	while ((*current).getFNext() != NULL
			&& (*(*current).getFNext()).getFlightId() < id) {
		current = (*current).getFNext();
	}

	return current;
}

//returns the flight that has the exact flight id
Flight* AirlineReservationSystem::findFlight(const int id) const {
	Flight* current = fHead;

	while ((*current).getFNext() != NULL) {
		if ((*current).getFlightId() == id)
			return current;
		current = (*current).getFNext();
	}
	return current;
}

//adds a flight in the correct position of the flight list via the flight id if it doesn't exist
void AirlineReservationSystem::addFlight(const int flightId,
		const string fromCity, const string toCity) {

	if (!isFlightFound(flightId)) {

		Flight* addedFlight = new Flight(flightId, fromCity, toCity);

		//empty list
		if (fHead == NULL) {
			fHead = addedFlight;
			(*fHead).setFNext(NULL);
			(*fHead).setFPrev(NULL);
		}
		//nonempty list
		else {

			Flight* temp = traverseToFlight(flightId);

			if ((*temp).getFNext() != NULL) {

				//add to the middle
				(*addedFlight).setFNext((*temp).getFNext());
				(*addedFlight).setFPrev(temp);

				(*temp).setFNext(addedFlight);
				(*(*temp).getFNext()).setFPrev(addedFlight);

			} else {
				//add to the end
				(*temp).setFNext(addedFlight);
				(*addedFlight).setFPrev(temp);
				(*addedFlight).setFNext(NULL);
			}
		}
		cout<<"Flight "<< flightId << " is added."<<endl;
	} else
		cout << "Error! Flight "<< flightId << " already exists." << endl;

}

//removes the flight with the specified id
void AirlineReservationSystem::removeFlight(const int flightId) {
	if (isFlightFound(flightId)) {
		Flight *current = traverseToFlight(flightId);
		//delete from the beginning
		if ((*fHead).getFlightId() == flightId) {
			Flight* temp = fHead;
			fHead = (*fHead).getFNext();
			(*fHead).setFPrev(NULL);
			delete temp;
			temp = NULL;
		} else {
			//delete from the end
			if ((*(*current).getFNext()).getFNext() == NULL) {
				delete (*current).getFNext();
				(*current).setFNext(NULL);
			}
			//delete from the beginning
			else {
				Flight* temp2 = (*current).getFNext(); //flight to be deleted
				(*current).setFNext((*temp2).getFNext());
				(*(*temp2).getFNext()).setFPrev(current);
				delete temp2;
				temp2 = NULL;
			}
		}
		cout<<"Flight "<< flightId << " is removed."<<endl;
	} else
		cout << "Flight " << flightId << " doesn't exist." << endl;
}

//adds a passenger to the specified flight
void AirlineReservationSystem::addPassenger(const int flightId,
		const string firstName, const string lastName) {

	if (isFlightFound(flightId)) {
		Flight *passengerFlight = findFlight(flightId);
		if((*passengerFlight).addPassenger(firstName, lastName))
			cout<<"Passenger "<< firstName << " " << lastName << " is added to Flight " << flightId << endl;
		else
			cout<<"Passenger "<< firstName << " " << lastName << " is does not exist in Flight " << flightId << endl;

	} else
		cout<< "Flight " << flightId << " does not exist." << endl;
}

//removes a specified passenger from a specified flight
void AirlineReservationSystem::removePassenger(const int flightId,
		const string firstName, const string lastName) {

	if (isFlightFound(flightId)) {
		Flight *passengerFlight = findFlight(flightId);
		if((*passengerFlight).removePassenger(firstName, lastName))
			cout<<"Passenger "<< firstName << " " << lastName << " is removed from Flight " << flightId << endl;
		else
			cout<<"Passenger "<< firstName << " " << lastName << " is does not exist in Flight " << flightId << endl;
	} else
		cout<< "Flight " << flightId << " does not exist." << endl;

}

//shows a specified flight's passenger list
void AirlineReservationSystem::showFlight(const int flightId) const {
	cout << "\n***Flight " << flightId;

	bool exists = false;
	Flight* temp = fHead;
	while (temp != NULL) {
		if ((*temp).getFlightId() == flightId)
			exists = true;
		temp = (*temp).getFNext();
	}

	Flight* current = findFlight(flightId);
	if (exists) {
		cout << ": from " << (*current).getFromCity() << " to "
				<< (*current).getToCity() << ": ***" << endl;
		(*current).displayPassengers();
	} else
		cout << " does not exist. ***" << endl;

	cout<<endl;
}

//Shows all the flights of a passenger
void AirlineReservationSystem::showPassenger(const string firstName,
		const string lastName) const {

	cout << "\n***Flights for " << firstName << " " << lastName << ": ***"
			<< endl;
	for (Flight* current = fHead; current != NULL; current
			= (*current).getFNext()) {
		if ((*current).doesPassengerExist(firstName, lastName))
			cout << "Flight " << (*current).getFlightId() << ": from "
					<< (*current).getFromCity() << " to "
					<< (*current).getToCity() << endl;
	}
	cout<<endl;
}

//shows all the flights in an airline reservation system and prints all their passengers
void AirlineReservationSystem::showAllFlights() const {
	Flight* current = fHead;
	if (current == NULL)
		cout << "No flights exist!" << endl;
	else {
		cout << "\n***Flights in this airline reservation system: ***" << endl;
		while (current != NULL) {
			cout << "\nFlight " << (*current).getFlightId() << ": from "
					<< (*current).getFromCity() << " to "
					<< (*current).getToCity() << endl;
			(*current).displayPassengers();
			current = (*current).getFNext();
		}
	}
	cout<<endl;
}
