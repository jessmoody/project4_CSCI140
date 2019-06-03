#include "Machine.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

void MachineD::machineAccepts()
{
	cout << "This machine accepts coins, one-dollar bills, credit card." << endl;
}
bool MachineD::acceptMoney(int index)
{
	int option;
	cout << "Select an option (1- dollar bill 2 - coins and 3- credit card) --> ";
	cin >> option;
	if (option == 1)
	{
		return MachineA::acceptMoney(index);
	}
	else if (option == 2)
	{
		return MachineB::acceptCoins(index);
	}
	else if (option == 3)
	{
		return MachineC::acceptMoney(index);
	}
	else
	{
		cout << "This option is not support in this machine . \n";
		return false;
	}
}