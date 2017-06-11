/*
 * AirlineReservationSystem.h
 *
 *  Created on: Jul 16, 2015
 *  Author: Gulsum Gudukbay
 *  Student ID: 21401148
 */

#ifndef AIRLINERESERVATIONSYSTEM_H_
#define AIRLINERESERVATIONSYSTEM_H_
#include "Flight.h"
#include <string>


class AirlineReservationSystem {
public:
	AirlineReservationSystem();
	~AirlineReservationSystem();
	Flight* traverseToFlight(const int id)const;
	Flight* findFlight(const int id)const;
	bool isFlightFound(const int id)const;
	void addFlight(const int flightId, const string fromCity,
			const string toCity);
	void removeFlight(const int flightId);
	void addPassenger(const int flightId, const string firstName,
			const string lastName);
	void removePassenger(const int flightId, const string firstName,
			const string lastName);
	void showFlight(const int flightId) const;
	void showPassenger(const string firstName, const string lastName) const;
	void showAllFlights() const;
private:
	Flight* fHead;
};

#endif /* AIRLINERESERVATIONSYSTEM_H_ */
