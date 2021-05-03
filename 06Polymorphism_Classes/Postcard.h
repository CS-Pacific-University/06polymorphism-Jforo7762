#pragma once

#include "Parcel.h"
#include <string>
#include <iostream>

class Postcard : public Parcel
{
public:
	Postcard();

	int getDeliveryDay() const;

	void setInsured();
	void setRush();

	bool read(istream& rcIn);
	void print(ostream& rcOut) const;

private:
	string mMessage;
};