#pragma once

#include "Parcel.h"
#include <string>
#include <iostream>

class Overnight : public Parcel
{
public:
	Overnight();

	int getDeliveryDay() const;

	void setInsured();
	void setRush();

	bool read(istream& rcIn);
	void print(ostream& rcOut) const;

private:
	int mVolume;
};