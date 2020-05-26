
#ifndef Charges_hpp
#define Charges_hpp

#include <stdio.h>

class Charge {
	int hours;
	float pricePerHour;
public:
	void setData(int hours, float price) {
		this->hours = hours; this->pricePerHour = price;
	}
	float calculateCharge();

};


#endif /* Charges_hpp */
