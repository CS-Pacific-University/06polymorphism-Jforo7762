//****************************************************************************** 
// File name:	 Parcel.cpp
// Author:		 Joseph Foroughi
// Date:		   4/24/2021
// Class:		   CS 250
// Assignment: Polymorphism
// Purpose:		 Demonstrate Polymorphism
//******************************************************************************


#include "Parcel.h"
#include <iostream>
#include <iomanip>

using namespace std;


//******************************************************************************
// Constructor:	Parcel
//
// Description:	Calls the Parcel default constructor, sets all member variables
//							to a default state
//
// Parameters:	none
//
// Returned:		none
//******************************************************************************
Parcel::Parcel() {
	mTrackingID = 0;
	mTo = "";
	mFrom = "";

	mWeight = 0;
	mDistance = 0;

	mbInsured = false;
	mbRush = false;
};

//******************************************************************************
// Function:	  getWeight
//
// Description:	Returns the weight of a parcel
//
// Parameters:	none
//
// Returned:	  int -  the weight of a parcel
//******************************************************************************
int Parcel::getWeight() const {
	return mWeight;
};

//******************************************************************************
// Function:	  getDistance
//
// Description:	Returns the distance a parcel will travel
//
// Parameters:	none
//
// Returned:	  int - the distance a parcel will travel
//******************************************************************************
int Parcel::getDistance() const {
	return mDistance;
};

//******************************************************************************
// Function:	  getInsured
//
// Description:	Returns whether the parcel has been insured
//
// Parameters:	none
//
// Returned:	  bool - the insurance status
//******************************************************************************
bool Parcel::getInsured() const {
	return mbInsured;
};

//******************************************************************************
// Function:	  getRush
//
// Description:	Returns whether the parcel has been rushed
//
// Parameters:	none
//
// Returned:	  bool - the rushing status
//******************************************************************************
bool Parcel::getRush() const
{
	return mbRush;
};

//******************************************************************************
// Function:	  getTID
//
// Description:	Returns the tracking ID
//
// Parameters:	none
//
// Returned:	  int - the tracking ID
//******************************************************************************
int Parcel::getTID() const {
	return mTrackingID;
};

void Parcel::setInsured() {
	mbInsured = true;
};

void Parcel::setRush() {
	mbRush = true;
};

void Parcel::setCost(double cost) {
	mCost = cost;
};

//******************************************************************************
// Function:	  read
//
// Description:	Input values to Parcel from stream
//
// Parameters:	rcIn - the stream to input values from
//
// Returned:	  valid - checks validity of input
//******************************************************************************
bool Parcel::read(istream &rcIn) {
	bool valid = true;

	rcIn >> mTrackingID
			 >> mTo
		   >> mFrom
		   >> mWeight
		   >> mDistance;

	return valid;
};


//******************************************************************************
// Function:	  print
//
// Description:	Prints the Parcel to the stream
//
// Parameters:	rcOut - the stream to print to
//
// Returned:	  none
//******************************************************************************
void Parcel::print(ostream& rcOut) const {
	rcOut << "TID: " << mTrackingID << "\t"
				<< "From: " << mFrom << "\t"
				<< "To: " << mTo << "\t";
	if (mbInsured) {
		rcOut << "INSURED" << "\t";
	}
	if (mbRush) {
		rcOut << "RUSH" << "\t";
	}

};

//******************************************************************************
// Function:	  getCost
//
// Description:	Returns the cost of delivery
//
// Parameters:	none
//
// Returned:	  double - the cost of delivery
//******************************************************************************
double Parcel::getCost() const {
	return mCost;
};

//******************************************************************************
// Function:	  getDeliverDay
//
// Description:	Pure virtual function, to be redefined in class to
//							Calculate and returns the amounts of days until that
//							specific parcel is delivered
//
// Parameters:	none
//
// Returned:	  int - the amount of days to deliver
//******************************************************************************
int Parcel::getDeliveryDay() const {
	return 1;
};