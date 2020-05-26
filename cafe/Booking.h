//
//  Booking.hpp
//  cafee system
//
//  Created by Youssef Abbas on 5/25/20.
//  Copyright © 2020 Youssef Abbas. All rights reserved.
//

#ifndef Booking_hpp
#define Booking_hpp
#include <vector>
#include <iostream>
#include<ctime>

using namespace std;

struct BookingModel {
	int memberID;
	int computerID;
	string customerName;
	tm* startTime;
	tm* endTime;
	bool isActive;
};

class Booking {
protected:
	vector<BookingModel> book_list;

public:
	void memberLogIn(vector<int> compIDs);
	void memberLogOut();
	void listOfMembers();
	BookingModel getData();
	bool isEmpty();
};

#endif /* Booking_hpp */
