

#include "Computer.h"
#include <string>
#include <fstream>
#include<iomanip>

using namespace std;



void Computer::showComputerData() const {
	// method to retrive all computers are avilable in syber
	// like foreach in c# but this for Vestor
	for (auto data : computer_data) {
		cout << "Computer name                : " << data.Computer_name << endl;
		cout << "Computer ip_Adress           : " << data.ip_Adress << endl;
		cout << "computer processor model     : " << data.processor_model << endl;
		cout << "Computer unique code         : " << data.unique_code << endl;
		cout << "_________________________________________" << endl;
	}
}

void Computer::addNewComputer() {
	// method to add new computer for list
	Computer_data tempComputerData;
	cout << "Enter Computer name                : ";
	cin >> tempComputerData.Computer_name;
	cout << "Enter the ip Adress of Computer : ";
	char ip_Adress[12];
	cin >> ip_Adress;
	strcpy_s(tempComputerData.ip_Adress, ip_Adress);
	cout << "Enter computer processor model     : ";
	cin >> tempComputerData.processor_model;
	bool is_unique = false;

	cout << "Enter Computer unique code         : ";
	int tempID;
	cin >> tempID;
	for (auto x : computer_data) {
		if (tempID == x.unique_code) {
			is_unique = false;
			cout << "the id is arrady used " << endl;
			return;
		}
		else {
			is_unique = true;
		}
	}
	tempComputerData.unique_code = tempID;

	this->computer_data.push_back(tempComputerData);
}

void Computer::deleteComputer() {
	//method to delete computer
	showComputerData();
	cout << "enter computer id that you want to delete" << endl;
	int tempId;
	cin >> tempId;
	bool found = false;
	int index = 0;
	for (auto x : computer_data) {
		if (tempId == x.unique_code) {
			found = true;
			break;
		}
		index++;
	}

	if (!found) {
		cout << "this id is not found " << endl;
		deleteComputer();
	}
	else {
		computer_data.erase(computer_data.begin() + index);
	}

}
vector<int> Computer::getComputersIDs() {
	vector<int> ids;
	for (auto id : computer_data) {
		ids.push_back(id.unique_code);
	}
	return ids;

}


bool Computer::isEmpty() {
	return computer_data.empty();
}