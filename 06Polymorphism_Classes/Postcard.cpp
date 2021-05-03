#include "Postcard.h"
#include <iostream>

using namespace std;

Postcard::Postcard() : Parcel() {
	mMessage = "";
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
int Postcard::getDeliveryDay() const {
	int day;

	day = getDistance() / 10;
	if (Parcel::getRush()) {
		day -= 2;
	}
	if (day < 1) {
		day = 1;
	}

	return day;
};

//******************************************************************************
// Function:	  setInsured
//
// Description:	Marks a postcard to be insured and increments price accordingly
//
// Parameters:	none
//
// Returned:	  none
//******************************************************************************
void Postcard::setInsured() {
	double cost;
	cost = Parcel::getCost();

	if (!Parcel::getInsured()) {
		cost += 0.15;
		Parcel::setCost(cost);
		Parcel::setInsured();
		cout << "Added Insurance for $0.15" << endl;
	}
};

//******************************************************************************
// Function:	  setInsured
//
// Description:	Marks a postcard to be insured and increments price accordingly
//
// Parameters:	none
//
// Returned:	  none
//******************************************************************************
void Postcard::setRush() {
	double cost;
	cost = Parcel::getCost();

	if (!Parcel::getRush()) {
		cost += 0.25;
		Parcel::setCost(cost);
		Parcel::setRush();
		cout << "Added Rush for $0.25" << endl;
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
bool Postcard::read(istream& rcIn) {
	bool valid;
	valid = Parcel::read(rcIn);

	rcIn >> mMessage;

	Parcel::setCost(0.15);

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
void Postcard::print(ostream& rcOut) const {
	Parcel::print(rcOut);

	rcOut << mMessage << endl;
};