

#ifndef Computer_hpp
#define Computer_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

struct Computer_data {
	std::string Computer_name;
	char ip_Adress[12];
	std::string processor_model;
	int unique_code;
};
using namespace std;
class Computer
{
protected:
	vector<Computer_data> computer_data;

public:
	void showComputerData() const;
	void addNewComputer();
	void deleteComputer();
	void ComputerEntryfun();
	vector<int> getComputersIDs();
	bool isEmpty();

};

#endif /* master_hpp */
