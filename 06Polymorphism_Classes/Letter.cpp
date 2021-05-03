#include "Letter.h"
#include <iostream>
#include <iomanip>

using namespace std;

Letter::Letter() : Parcel() {
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
int Letter::getDeliveryDay() const {
	int day;

	day = getDistance() / 100;
	if (Parcel::getRush()) {
		day -= 1;
	}
	if (day < 1) {
		day = 1;
	}

	return day;
};

//******************************************************************************
// Function:	  setInsured
//
// Description:	Marks a letter to be insured and increments price accordingly
//
// Parameters:	none
//
// Returned:	  none
//******************************************************************************
void Letter::setInsured()
{
	double cost;
	cost = Parcel::getCost();

	if (!Parcel::getInsured()) {
		cost += 0.45;
		Parcel::setCost(cost);
		cout << "Added Insurance for $0.45" << endl;
		Parcel::setInsured();
	}
};
//******************************************************************************
// Function:	  setInsured
//
// Description:	Marks a letter to be rushed and increments price accordingly
//
// Parameters:	none
//
// Returned:	  none
//******************************************************************************
void Letter::setRush() {
	double cost;
	double added;
	cost = Parcel::getCost();
	added = cost * 0.10;

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
// Description:	Input values to Postcard from stream
//
// Parameters:	rcIn - the stream to input values from
//
// Returned:	  valid - checks validity of input
//******************************************************************************
bool Letter::read(istream& rcIn) {
	bool valid;
	double cost;

	valid = Parcel::read(rcIn);

	cost = Parcel::getWeight() * 0.45;
	Parcel::setCost(cost);

	return valid;
};


//******************************************************************************
// Function:	  print
//
// Description:	Prints the Postcard to the stream
//
// Parameters:	rcOut - the stream to print to
//
// Returned:	  none
//******************************************************************************
void Letter::print(ostream& rcOut) const {
	Parcel::print(rcOut);

	rcOut << endl;
};