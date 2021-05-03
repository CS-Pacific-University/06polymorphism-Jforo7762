#pragma once

#include "Parcel.h"
#include <string>
#include <iostream>

class Letter : public Parcel
{
public:
	Letter();

	int getDeliveryDay() const;

	void setInsured();
	void setRush();

	bool read(istream& rcIn);
	void print(ostream& rcOut) const;
};