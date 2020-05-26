

#include <iostream>
#include <string>
//#include <process.h>
#include <fstream>
#include "Booking.h"
#include "Computer.h"
#include "Charges.h"
#include<ctime>
#pragma warning(disable: 4996)
using namespace std;
int main(int argc, const char* argv[]) {
	//initialization
	Computer computer;
	Booking booking;
	BookingModel temp;
	time_t ttime;
	int hours;

	Charge charge;
	int choice;
	// insert code here...
	do {



		cout << "\t\t\t\t           MENU         \n";

		cout << "\t1. computer managment";
		cout << "\n \t2. Cafe Managment  ";
		cout << "\n \t3. Exit : " << endl;;
		choice = 0;
		cin >> choice;
		bool ret;
		switch (choice)
		{
		case 1:
			ret = false;
			do {
				cout << "\n\n\n\n\t\t\t        ";
				cout << "\n\n";
				cout << "\t\t\t      MENU/MASTER ENTRY/COMPUTER ENTRY         ";
				cout << "\n\t1. Add Computer   ";
				cout << "\n \t2. Show Computers   ";
				cout << "\n \t3. Delete Computer   ";
				cout << "\n \t4. Return            \n";
				while (1) {
					cout << "\t\t\t\t Select Your Choice ->> ";
					choice = 0;
					cin >> choice;
					if (cin.good())
						break;
					cout << "\t\t\tInvalid choice enter a valid choice" << endl;
					cin.ignore(10, '\n');
				}
				switch (choice) {
				case 1:
					computer.addNewComputer();
					break;
				case 2:
					computer.showComputerData();
					break;

				case 3:
					computer.deleteComputer();
					break;
				case 4:
					ret = true;
					break;
				default:
					cout << "Invalid choice !";
					break;
				}

			} while (!ret);
			break;
		case 2:
			ret = false;
			do {
				cout << "\n\n\n\n\t\t\t        ";
				cout << "\t\t\t\t    MENU/CAFE MANAGMENT         \n";
				cout << "\n\t1. Booking         ";
				cout << "\n \t2. Charges         ";
				cout << "\n \t3. Return          \n";
				cout << "\n\n";
				choice = 0;
				cin >> choice;
				bool _ret = false;
				switch (choice) {
				case 1:
					_ret = false;
					do {
						cout << "\n\n\n\n\t\t\t        ";
						cout << "\n\n";
						cout << "\t\t\t       MENU/CAFE MANAGMENT/BOOKING         \n";
						cout << "\n\t1. Member login                  ";
						cout << "\n \t2. Member logout                 ";
						cout << "\n \t3. list of member                 ";
						cout << "\n \t4. Return                         \n";
						cout << "\n\n";
						choice = 0;
						cin >> choice;
						switch (choice) {
						case 1:
							booking.memberLogIn(computer.getComputersIDs());
							break;
						case 2:
							booking.memberLogOut();
							break;
						case 3:
							booking.listOfMembers();
							break;
						case 4:
							_ret = true;
							break;
						default:
							cout << "invalid choises " << endl;
							break;
						}
					} while (!_ret);
					break;
				case 2:
					if (!booking.isEmpty()) {
						cout << "enter price per hours : ";
						float price;
						cin >> price;
						booking.listOfMembers();
						temp = booking.getData();
						//to calculate houres
						ttime = time(0);
						hours = temp.startTime->tm_hour - localtime(&ttime)->tm_hour;
						hours++; // less time is 1 hour and any minut exstra it calculated as hour
						charge.setData(hours, price);
						float cha = charge.calculateCharge();
						cout << "charge for " << temp.customerName << "=" << cha << "$ , he take " << hours << "h" << endl;
					}
					else {
						cout << "there is no member " << endl;
					}

					break;
				case 3:
					ret = true;
					break;
				default:
					break;
				}

			} while (!ret);
		case 3:
			exit(0);
			break;
		default:
			cout << "Invalid choice ! Renter ";

			break;
		}
	} while (1);
	return 0;
}

