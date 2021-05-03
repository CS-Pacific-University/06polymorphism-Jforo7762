#pragma once

#include <iostream>

using namespace std;

class Parcel 
{
public:
	Parcel();

	int getWeight() const;
	int getDistance() const;
	bool getInsured() const;
	bool getRush() const;
	int getTID() const;

	virtual void setInsured();
	virtual void setRush();
	void setCost(double cost);

	virtual bool read(istream& rcIn);
	virtual void print(ostream& RcOut) const;

	double getCost() const;
	virtual int getDeliveryDay() const;

private:
	int mTrackingID;
	string mTo;
	string mFrom;

	double mCost;

	int mWeight;
	int mDistance;

	bool mbInsured;
	bool mbRush;
};