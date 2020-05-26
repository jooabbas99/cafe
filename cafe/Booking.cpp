
#include "Booking.h"
#include "Computer.h"
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
void Booking::memberLogIn(vector<int> compIDs) {
	listOfMembers();
	BookingModel tempBook;


	cout << "enter memberID : ";
	cin >> tempBook.memberID;
	int index = 0;
	bool found = false;
	for (auto x : book_list) {
		if (x.memberID == tempBook.memberID) {
			found = true;
			break;
		}
		index++;
	}
	if (found) {
		book_list[index].isActive = true;
		time_t ttime = time(0);
		book_list[index].startTime = localtime(&ttime);
	}
	else {
		cout << "enter member name  : ";
		cin >> tempBook.customerName;
	again:

		cout << "enter computerID : ";
		int tempID;
		cin >> tempID;
		bool isValidId = false;
		for (int i = 0; i < compIDs.size(); i++) {
			if (compIDs[i] == tempID) {
				isValidId = true;
			}
		}
		if (!isValidId) {
			cout << "this computer is not avilable " << endl;
			goto again;
		}
		for (auto x : book_list) {
			if (x.computerID == tempID) {
				cout << "this computer are used for other member " << endl;

				goto again;
				break;
			}
		}
		tempBook.computerID = tempID;
		time_t ttime = time(0);
		tempBook.startTime = localtime(&ttime);
		tempBook.isActive = true;
		book_list.push_back(tempBook);
	}

}

void Booking::listOfMembers() {
	for (auto member : book_list) {
		cout << "enter member name  : " << member.customerName << endl;
		cout << "enter memberID : " << member.memberID << endl;
		cout << "enter computerID : " << member.computerID << endl;
		cout << "\t\t\t---------------------------------------------" << endl;
	}
}

void Booking::memberLogOut() {
	listOfMembers();
	BookingModel tempBook;
again:
	cout << "enter MemberID : ";
	int tempID;
	cin >> tempID;
	int index = 0;
	bool found = false;
	for (auto x : book_list) {
		if (x.memberID == tempID) {
			found = true;
			break;
		}
		index++;
	}
	if (!found) {
		cout << "wrong id !!!!" << endl;
		goto again;
	}
	else {
		tempBook.isActive = false;
	}
	time_t ttime = time(0);
	tempBook.endTime = localtime(&ttime);
	book_list[index] = tempBook;
}

BookingModel Booking::getData() {
	BookingModel bookingTemp;
	bool found = false;

	do {
		cout << "enter MemberID : ";
		int tempID;
		cin >> tempID;
		for (auto x : book_list) {
			if (x.memberID == tempID) {
				found = true;
				bookingTemp = x;
				break;
			}
		}
		if (!found)
			cout << "wrong id !!!!" << endl;
	} while (!found);
	return bookingTemp;

}

bool Booking::isEmpty() {
	return book_list.empty();
}