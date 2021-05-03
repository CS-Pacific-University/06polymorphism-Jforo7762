#include "Overnight.h"
#include <iostream>
#include <iomanip>

using namespace std;

Overnight::Overnight() : Parcel() {
	mVolume = 0;
};

//******************************************************************************
// Function:	  getDeliveryDay
//
// Description:	Calculates and returns the number of days till delivery
//
// Parameters:	none
//
// Returned:	  int -  number of days to deliver
//******************************************************************************
int Overnight::getDeliveryDay() const {
	int day;

	if (Parcel::getRush() || (getDistance() <= 1000)) {
		day = 1;
	}
	else {
		day = 2;
	}

	return day;
};

//******************************************************************************
// Function:	  setInsured
//
// Description:	Marks an Overnight package to be insured and increments price
//							accordingly
//
// Parameters:	none
//
// Returned:	  none
//******************************************************************************
void Overnight::setInsured() {
	double cost;
	double added;
	cost = Parcel::getCost();
	added = cost * 0.25;

	if (!Parcel::getInsured()) {
		cost += added;
		Parcel::setCost(cost);
		cout << "Added Insurance for $";
		cout << fixed << setprecision(2) << added << endl;
		Parcel::setInsured();
	}
};

//******************************************************************************
// Function:	  setRush
//
// Description:	Marks an Overnight package to be rushed and increments price
//							accordingly
//
// Parameters:	none
//
// Returned:	  none
//******************************************************************************
void Overnight::setRush() {
	double cost;
	double added;
	cost = Parcel::getCost();
	added = cost * 0.75;

	if (!Parcel::getRush()) {
		cost += added;
		Parcel::setCost(cost);
		cout << "Added Rush for $";
		cout << fixed << setprecision(2) << added << endl;
		Parcel::setRush();
	}
};

//******************************************************************************
// Function:	  read
//
// Description:	Input values to Overnight from stream
//
// Parameters:	rcIn - the stream to input values from
//
// Returned:	  valid - checks validity of input
//******************************************************************************
bool Overnight::read(istream& rcIn) {
	bool valid;
	double cost;

	valid = Parcel::read(rcIn);

	rcIn >> mVolume;

	if (mVolume > 100) {
		cost = 20.0;
	}
	else {
		cost = 12.0;
	}
	Parcel::setCost(cost);

	return valid;
};


//******************************************************************************
// Function:	  print
//
// Description:	Prints the Overnight object to the stream
//
// Parameters:	rcOut - the stream to print to
//
// Returned:	  none
//******************************************************************************
void Overnight::print(ostream& rcOut) const {
	Parcel::print(rcOut);

	rcOut << "OVERNIGHT!" << endl;
};